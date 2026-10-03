	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _0808E968 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808E984
	ldr r0, _0808E96C @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r2, _0808E970 @ =0x00004022
	adds r5, r6, r2
	ldrh r3, [r5]
	adds r4, r3, #1
	subs r2, #4
	adds r0, r6, r2
	ldrb r0, [r0]
	adds r2, r4, #0
	muls r2, r0, r2
	ldr r0, [r1]
	adds r0, r0, r2
	ldr r1, _0808E974 @ =0x0000270F
	cmp r0, r1
	bgt _0808E984
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r0, r0, r3
	adds r2, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	cmp r0, r1
	bge _0808E984
	strh r4, [r5]
	ldr r0, _0808E978 @ =0x0000037D
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_0808e83c
	adds r0, r6, #0
	bl FUN_0808e734
	adds r0, r6, #0
	bl FUN_0808e5a8
	ldr r0, _0808E97C @ =0x00004020
	adds r4, r6, r0
	movs r0, #0x13
	strb r0, [r4]
	ldr r1, _0808E980 @ =0x00004021
	adds r5, r6, r1
	ldrb r0, [r5]
	bl FUN_0808e8b8
	adds r7, r0, #0
	ldrb r0, [r4]
	adds r3, r0, r7
	b _0808E9DC
	.align 2, 0
_0808E968: .4byte 0x030044E0
_0808E96C: .4byte 0x030046A0
_0808E970: .4byte 0x00004022
_0808E974: .4byte 0x0000270F
_0808E978: .4byte 0x0000037D
_0808E97C: .4byte 0x00004020
_0808E980: .4byte 0x00004021
_0808E984:
	ldr r0, _0808E9F0 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808EA08
	ldr r2, _0808E9F4 @ =0x00004022
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808EA08
	subs r0, #1
	strh r0, [r1]
	ldr r0, _0808E9F8 @ =0x0000037D
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_0808e83c
	adds r0, r6, #0
	bl FUN_0808e734
	adds r0, r6, #0
	bl FUN_0808e5a8
	ldr r0, _0808E9FC @ =0x00004020
	adds r4, r6, r0
	movs r0, #0x16
	strb r0, [r4]
	ldr r1, _0808EA00 @ =0x00004021
	adds r5, r6, r1
	ldrb r0, [r5]
	bl FUN_0808e8b8
	adds r7, r0, #0
	ldrb r0, [r4]
	adds r3, r0, r7
	ldr r2, _0808EA04 @ =0x00004024
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808E9DC
	movs r0, #1
	strh r0, [r1]
_0808E9DC:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0808EA40
	movs r0, #0
	strb r0, [r5]
	b _0808EA40
	.align 2, 0
_0808E9F0: .4byte 0x030044E0
_0808E9F4: .4byte 0x00004022
_0808E9F8: .4byte 0x0000037D
_0808E9FC: .4byte 0x00004020
_0808EA00: .4byte 0x00004021
_0808EA04: .4byte 0x00004024
_0808EA08:
	ldr r0, _0808EA34 @ =0x00004021
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0808EA3C
	bl FUN_0808e8b8
	adds r7, r0, #0
	ldr r1, _0808EA38 @ =0x00004020
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r3, r0, r7
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0808EA40
	movs r0, #0
	strb r0, [r4]
	b _0808EA40
	.align 2, 0
_0808EA34: .4byte 0x00004021
_0808EA38: .4byte 0x00004020
_0808EA3C:
	movs r7, #0
	movs r3, #0x12
_0808EA40:
	ldr r0, _0808EAAC @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808EA78
	ldr r0, _0808EAB0 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r2, r2, r4
	ldr r1, _0808EAB4 @ =0x00004022
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r0, #1
	ldr r4, _0808EAB8 @ =0x0000401E
	adds r1, r6, r4
	ldrb r1, [r1]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, _0808EABC @ =0x0000270F
	cmp r0, r1
	ble _0808EA78
	ldr r0, _0808EAC0 @ =0x00004024
	adds r1, r6, r0
	movs r0, #0x3c
	strh r0, [r1]
_0808EA78:
	ldr r2, _0808EAC0 @ =0x00004024
	adds r1, r6, r2
	ldrh r0, [r1]
	movs r4, #0xc0
	adds r4, r4, r6
	mov r8, r4
	lsls r5, r3, #0x10
	cmp r0, #0
	beq _0808EB0A
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0808EAC8
	adds r0, r6, #0
	bl FUN_0808e5a8
	movs r0, #4
	bl TextBox_ShowLine
	ldr r1, _0808EAC4 @ =0x00004026
	adds r0, r6, r1
	strh r4, [r0]
	b _0808EB0A
	.align 2, 0
_0808EAAC: .4byte 0x030044E0
_0808EAB0: .4byte 0x030046A0
_0808EAB4: .4byte 0x00004022
_0808EAB8: .4byte 0x0000401E
_0808EABC: .4byte 0x0000270F
_0808EAC0: .4byte 0x00004024
_0808EAC4: .4byte 0x00004026
_0808EAC8:
	ldr r2, _0808EB30 @ =0x0000390C
	adds r0, r6, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r4, #1
	ldr r0, _0808EB34 @ =0x0000396C
	adds r2, r6, r0
	ldr r0, _0808EB38 @ =0x0000378C
	adds r1, r6, r0
	movs r3, #3
_0808EAE0:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0808EAE0
	ldr r1, _0808EB3C @ =0x00004026
	adds r4, r6, r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _0808EB0A
	movs r0, #6
	bl TextBox_ShowLine
	movs r0, #1
	strh r0, [r4]
_0808EB0A:
	ldr r2, _0808EB40 @ =0x00003604
	adds r0, r6, r2
	lsrs r2, r5, #0x10
	mov r1, r8
	movs r3, #1
	bl MainSprite_SetPose
	ldr r4, _0808EB44 @ =0x00000BE4
	adds r0, r6, r4
	ldr r2, _0808EB48 @ =0x00000143
	adds r1, r7, r2
	bl Video_SetAuxSpritePltt
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808EB30: .4byte 0x0000390C
_0808EB34: .4byte 0x0000396C
_0808EB38: .4byte 0x0000378C
_0808EB3C: .4byte 0x00004026
_0808EB40: .4byte 0x00003604
_0808EB44: .4byte 0x00000BE4
_0808EB48: .4byte 0x00000143
