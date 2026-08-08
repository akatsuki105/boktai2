	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080EAFEC
	b _080EB160
_080EAFEC:
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080EAFFA
	b _080EB160
_080EAFFA:
	ldr r2, _080EB010 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080EB014
	movs r0, #1
	b _080EB016
	.align 2, 0
_080EB010: .4byte 0x000001DF
_080EB014:
	movs r0, #0
_080EB016:
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r6, r5, r3
	cmp r0, #0
	bne _080EB108
	movs r1, #4
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080EB02E
	movs r0, #1
	b _080EB030
_080EB02E:
	movs r0, #0
_080EB030:
	cmp r0, #0
	beq _080EB03C
	ldr r0, _080EB038 @ =0xFFFFF678
	b _080EB152
	.align 2, 0
_080EB038: .4byte 0xFFFFF678
_080EB03C:
	movs r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080EB04A
	movs r0, #1
	b _080EB04C
_080EB04A:
	movs r0, #0
_080EB04C:
	cmp r0, #0
	beq _080EB0C8
	movs r1, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	movs r2, #0
	strb r1, [r0]
	ldr r1, _080EB0B4 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _080EB0B8 @ =0x0000046A
	adds r0, r5, r3
	strb r2, [r0]
	adds r7, #0x1c
	adds r0, r5, r7
	str r2, [r0]
	adds r1, #3
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r3, _080EB0BC @ =0x00000594
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #7
	subs r7, #0x17
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _080EB0C0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	movs r7, #0xc7
	lsls r7, r7, #1
	adds r0, r5, r7
	ldrh r0, [r0]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _080EB0C4 @ =0xFFFFF67C
	b _080EB152
	.align 2, 0
_080EB0B4: .4byte 0x00000469
_080EB0B8: .4byte 0x0000046A
_080EB0BC: .4byte 0x00000594
_080EB0C0: .4byte 0x0000046B
_080EB0C4: .4byte 0xFFFFF67C
_080EB0C8:
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080EB0D8
	movs r0, #1
	b _080EB0DA
_080EB0D8:
	movs r0, #0
_080EB0DA:
	cmp r0, #0
	beq _080EB0EC
	adds r0, r5, #0
	bl 0x080f0b3c @ TODO: Replace by FUN_080f0b3c
	ldr r0, _080EB0E8 @ =0xFFFFF67E
	b _080EB152
	.align 2, 0
_080EB0E8: .4byte 0xFFFFF67E
_080EB0EC:
	movs r1, #1
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080EB0FA
	movs r0, #1
	b _080EB0FC
_080EB0FA:
	movs r0, #0
_080EB0FC:
	cmp r0, #0
	beq _080EB108
	ldr r0, _080EB104 @ =0xFFFFFE7E
	b _080EB152
	.align 2, 0
_080EB104: .4byte 0xFFFFFE7E
_080EB108:
	movs r1, #0x80
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080EB116
	movs r0, #1
	b _080EB118
_080EB116:
	movs r0, #0
_080EB118:
	cmp r0, #0
	beq _080EB128
	ldr r3, _080EB124 @ =0x000005AC
	adds r0, r5, r3
	b _080EB144
	.align 2, 0
_080EB124: .4byte 0x000005AC
_080EB128:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080EB138
	movs r0, #1
	b _080EB13A
_080EB138:
	movs r0, #0
_080EB13A:
	cmp r0, #0
	beq _080EB160
	movs r7, #0xb6
	lsls r7, r7, #3
	adds r0, r5, r7
_080EB144:
	ldr r1, [r0]
	cmp r1, #0
	beq _080EB150
	adds r0, r5, #0
	bl _call_via_r1
_080EB150:
	ldr r0, _080EB15C @ =0xFFFFFE7F
_080EB152:
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r0, #1
	b _080EB162
	.align 2, 0
_080EB15C: .4byte 0xFFFFFE7F
_080EB160:
	movs r0, #0
_080EB162:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
