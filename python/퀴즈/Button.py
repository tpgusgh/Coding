import streamlit as st
if 'key' not in st.session_state:
    st.session_state.key = 0

st.title('객관식 30점')

option = st.selectbox(
    "현호가 좋아하는 게임은?",
    ("리그오브레전드","원신","냥코대전쟁","로블록스","ARK")
)
if option == '원신':
    st.session_state.key += 30
else:
    st.session_state.key += 0

st.title('주관식 70점')
love = st.text_input("현호가 좋아하는 사람")

if love == '여자친구':
    st.session_state.key += 70
else:
    st.session_state.key += 0

st.button("제출", type="primary")