	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	bl FUN_0808b82c
	ldr r1, [r7, #0x2c]
	movs r0, #0
	movs r2, #4
	bl Video_SetBGLayer
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0808ED2C @ =0x000034EC
	adds r1, r7, r0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	ldr r1, _0808ED30 @ =0x000034E4
	adds r0, r7, r1
	adds r6, r7, #0
	adds r6, #0xc0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #5
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r2, _0808ED34 @ =0x00004022
	adds r0, r7, r2
	strh r4, [r0]
	adds r0, r7, #0
	bl FUN_0808e734
	adds r0, r7, #0
	bl FUN_0808e83c
	ldr r0, _0808ED38 @ =0x00000BB8
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r2, _0808ED3C @ =0x0000360C
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r0, _0808ED40 @ =0x00003624
	adds r1, r7, r0
	movs r0, #0x10
	strh r0, [r1]
	adds r2, #0x1a
	adds r1, r7, r2
	ldr r0, _0808ED44 @ =0x0000FFFC
	strh r0, [r1]
	ldr r1, _0808ED48 @ =0x00003604
	adds r0, r7, r1
	adds r1, r6, #0
	movs r2, #0x12
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _0808ED4C @ =0x0000390C
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r1, _0808ED50 @ =0x00003904
	adds r0, r7, r1
	ldr r2, _0808ED54 @ =0x0000401E
	adds r1, r7, r2
	ldrb r2, [r1]
	adds r2, #7
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _0808ED58 @ =0x0000396C
	adds r2, r7, r0
	ldr r0, _0808ED5C @ =0x0000378C
	adds r1, r7, r0
	movs r3, #3
_0808ECCA:
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r0, [r2]
	ands r0, r5
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0808ECCA
	movs r4, #0
	adds r0, r7, #0
	bl FUN_0808e5a8
	ldr r1, _0808ED60 @ =0x00004024
	adds r0, r7, r1
	movs r1, #0
	strh r4, [r0]
	ldr r2, _0808ED64 @ =0x00004026
	adds r0, r7, r2
	strh r4, [r0]
	subs r2, #5
	adds r0, r7, r2
	strb r1, [r0]
	ldr r1, _0808ED48 @ =0x00003604
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0xc0
	movs r2, #0x12
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _0808ED68 @ =0x00000BE4
	adds r0, r7, r2
	ldr r1, _0808ED6C @ =0x00000143
	bl Video_SetAuxSpritePltt
	movs r0, #4
	bl TextBox_ShowLine
	ldr r1, _0808ED70 @ =FUN_0808ef58
	adds r0, r7, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808ED2C: .4byte 0x000034EC
_0808ED30: .4byte 0x000034E4
_0808ED34: .4byte 0x00004022
_0808ED38: .4byte 0x00000BB8
_0808ED3C: .4byte 0x0000360C
_0808ED40: .4byte 0x00003624
_0808ED44: .4byte 0x0000FFFC
_0808ED48: .4byte 0x00003604
_0808ED4C: .4byte 0x0000390C
_0808ED50: .4byte 0x00003904
_0808ED54: .4byte 0x0000401E
_0808ED58: .4byte 0x0000396C
_0808ED5C: .4byte 0x0000378C
_0808ED60: .4byte 0x00004024
_0808ED64: .4byte 0x00004026
_0808ED68: .4byte 0x00000BE4
_0808ED6C: .4byte 0x00000143
_0808ED70: .4byte FUN_0808ef58
