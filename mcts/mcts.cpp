#include <utility>

#include "3rd_party.hpp"

struct Mcts {
  Mcts() : root_(make_unique<Node>(nullptr, "Root")) {}

  struct Node {
    explicit Node(Node *const parent, const string &act) :
        children_(),
        parent_(parent),
        action_(act),
        Q(0.0f),
        N(0) {
      std::cout << absl::StrCat("Node ", action_, " is added!\n");
    };

    const auto &GetChildren() const {
      return children_;
    }

    void AddChild(unique_ptr<Node> np) {
      children_.emplace_back(std::move(np));
    }

    Node *parent_;
    const string action_;
    float Q;  // quality (of this node)
    int N;    // visit count

   private:
    vector<unique_ptr<Node>> children_;
  };

  void PrintTree() {
    RecurPrint(root_.get(), 0);
  }

  unique_ptr<Node> root_;

 private:
  void RecurPrint(Node *const pn, int padding) const {
    if (pn == nullptr) {
      return;
    }

    cout << absl::StrJoin(vector<string>(padding, "-"), "") << pn->action_ << '\n';
    for (const auto &upc : pn->GetChildren()) {
      RecurPrint(upc.get(), padding + 2);
    }
  }

};

float UCB1(const Mcts::Node &node) {
  if (node.N == 0) {
    return numeric_limits<float>::max();
  }

  // UCB1 = average_value + c * sqrt(ln(N)/n_i)
  return node.Q / node.N + 2 * sqrt(node.parent_->N / node.N);
}

using SelectPolicy = decltype(UCB1);

void Simulate(Mcts &mcts, SelectPolicy policy) {
  // select the max element based on 'policy'
  Mcts::Node *p_current = mcts.root_.get();

  // 'Select' until reaching leaf node (no children for current node)
  vector<Mcts::Node *> walk_path = {p_current};
  while (!p_current->GetChildren().empty()) {
    auto result = max_element(begin(p_current->GetChildren()),
                              end(p_current->GetChildren()),
                              [policy](const auto &lhs, const auto &rhs) {
                                return policy(*lhs) < policy(*rhs);
                              })->get();
    p_current = result;
    walk_path.push_back(p_current);
  }

  // expand
  for (int i : {1, 2}) {
    p_current->AddChild(make_unique<Mcts::Node>(p_current, absl::StrCat(i)));
  }

  // rollout


  // backpropagate

}

int main() {
  Mcts mcts;
  Simulate(mcts, UCB1);
  Simulate(mcts, UCB1);

  mcts.PrintTree();
}
