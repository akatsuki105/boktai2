	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	ldr r0, _080F5FC4 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F5FC8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F5FCA
	.align 2, 0
_080F5FC4: .4byte 0x0000046D
_080F5FC8:
	movs r0, #0
_080F5FCA:
	cmp r0, #0
	beq _080F5FF0
	ldr r1, _080F6058 @ =0x000001DD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #3
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	subs r0, #0x40
	movs r4, #0
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r2, _080F605C @ =0x0000046E
	adds r0, r7, r2
	strb r4, [r0]
_080F5FF0:
	cmp r5, #0x3c
	bgt _080F5FF6
	b _080F622C
_080F5FF6:
	ldr r3, _080F605C @ =0x0000046E
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F6002
	b _080F622C
_080F6002:
	ldr r5, _080F6060 @ =0x0000046B
	adds r1, r7, r5
	movs r0, #1
	strb r0, [r1]
	ldr r6, _080F6064 @ =0x000001DF
	adds r0, r7, r6
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080F6052
	cmp r1, #0
	blt _080F6052
	ldr r0, _080F6068 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080F6052
	ldr r0, _080F606C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F6070
_080F6052:
	movs r4, #0
	b _080F607E
	.align 2, 0
_080F6058: .4byte 0x000001DD
_080F605C: .4byte 0x0000046E
_080F6060: .4byte 0x0000046B
_080F6064: .4byte 0x000001DF
_080F6068: .4byte 0x030046A8
_080F606C: .4byte 0x030046AC
_080F6070:
	ldr r0, _080F6090 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080F607E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F6094
	adds r0, #4
	b _080F60A0
	.align 2, 0
_080F6090: .4byte 0x030046A4
_080F6094:
	ldr r0, _080F60B4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F60A0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080F60B8
	cmp r2, #2
	beq _080F60BC
	b _080F60C0
	.align 2, 0
_080F60B4: .4byte 0x030046A4
_080F60B8:
	ldrb r0, [r5, #4]
	b _080F60BE
_080F60BC:
	ldrb r0, [r5]
_080F60BE:
	subs r1, r1, r0
_080F60C0:
	strh r1, [r5, #2]
	ldr r2, _080F60EC @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080F60F0
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _080F6116
	.align 2, 0
_080F60EC: .4byte 0x000004A4
_080F60F0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080F6110
	cmp r0, #2
	beq _080F610C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080F610C:
	movs r0, #1
	b _080F6120
_080F6110:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_080F6116:
	ldr r1, _080F6170 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_080F6120:
	adds r4, r0, #0
	cmp r4, #0
	bne _080F618C
	ldr r1, _080F6174 @ =FUN_080e48d0
	ldr r2, _080F6178 @ =0x0000046D
	adds r0, r7, r2
	movs r3, #1
	strb r3, [r0]
	ldr r5, _080F617C @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	ldr r6, _080F6180 @ =0x00000553
	adds r0, r7, r6
	strb r4, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r1, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _080F6184 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	ldr r5, _080F6188 @ =0x0000046A
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	b _080F622C
	.align 2, 0
_080F6170: .4byte 0xFFFFFDFF
_080F6174: .4byte FUN_080e48d0
_080F6178: .4byte 0x0000046D
_080F617C: .4byte 0x0000046B
_080F6180: .4byte 0x00000553
_080F6184: .4byte 0x00000469
_080F6188: .4byte 0x0000046A
_080F618C:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	movs r4, #0
	movs r5, #0
	movs r2, #1
	movs r6, #1
	strh r6, [r0, #6]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _080F6234 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r5, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	ldr r0, _080F6238 @ =FUN_080e6794
	mov ip, r0
	movs r1, #0xe
	adds r3, #1
	adds r0, r7, r3
	strb r2, [r0]
	ldr r2, _080F623C @ =0x0000046B
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, ip
	str r2, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r5, [r0]
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080F6240 @ =0x00000482
	adds r0, r7, r1
	strh r6, [r0]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _080F6244 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _080F6248 @ =0x00000552
	adds r0, r7, r3
	strb r5, [r0]
_080F622C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F6234: .4byte 0x00000469
_080F6238: .4byte FUN_080e6794
_080F623C: .4byte 0x0000046B
_080F6240: .4byte 0x00000482
_080F6244: .4byte 0x00000551
_080F6248: .4byte 0x00000552
