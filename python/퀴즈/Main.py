import streamlit as st
import pandas as pd
import numpy as np


st.title('현호 블로그')

chart_data = pd.DataFrame(np.random.randn(20,3),  columns=["접속률","실행한 수","좋아요 누른 수"])


st.bar_chart(chart_data)

