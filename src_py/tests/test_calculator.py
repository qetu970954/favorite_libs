import requests
from calculator import Calculator
import requests


def test_version():
    cal = Calculator()
    assert cal.add(3, 4) == 7
