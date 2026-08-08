	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _080FAE36
	b _080FB4BC
_080FAE36:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080FAE60
	ldr r3, _080FAE5C @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FAE4E
	b _080FB4BC
_080FAE4E:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _080FB4BC
	.align 2, 0
_080FAE5C: .4byte 0x0000048C
_080FAE60:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _080FAE70
	b _080FB4BC
_080FAE70:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _080FAE80
	b _080FB18C
_080FAE80:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _080FAE92
	b _080FB4BC
_080FAE92:
	ldr r2, _080FAF24 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _080FAEA6
	b _080FB4BC
_080FAEA6:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080FAEB4
	b _080FB4BC
_080FAEB4:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _080FAECC
	b _080FB014
_080FAECC:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _080FAF34
	ands r3, r1
	cmp r3, #0
	beq _080FAF34
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _080FAEF2
	rsbs r1, r1, #0
_080FAEF2:
	cmp r1, #0x20
	bgt _080FAF34
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _080FAF28 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _080FAF2C @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _080FAF30 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _080FB4BC
	.align 2, 0
_080FAF24: .4byte 0x0000A007
_080FAF28: .4byte 0x000004BE
_080FAF2C: .4byte 0x0000048C
_080FAF30: .4byte 0x0000044E
_080FAF34:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _080FAF5C @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080FAF64
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _080FAF60 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _080FAFD2
	.align 2, 0
_080FAF5C: .4byte 0x0000048A
_080FAF60: .4byte 0x03002BE0
_080FAF64:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080FAF80
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _080FAF7C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _080FAFD2
	.align 2, 0
_080FAF7C: .4byte 0x03002BE0
_080FAF80:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _080FAF9C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _080FAF98 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _080FAFD2
	.align 2, 0
_080FAF98: .4byte 0x03002BE0
_080FAF9C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _080FAFB8
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _080FAFB4 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _080FAFD2
	.align 2, 0
_080FAFB4: .4byte 0x03002BE0
_080FAFB8:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080FAFCA
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _080FAFD2
_080FAFCA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _080FAFD4
_080FAFD2:
	movs r3, #1
_080FAFD4:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _080FB008 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _080FAFF6
	b _080FB14C
_080FAFF6:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080FB00C
	movs r0, #1
	b _080FB00E
	.align 2, 0
_080FB008: .4byte 0x0000049C
_080FB00C:
	movs r0, #0
_080FB00E:
	cmp r0, #0
	bne _080FB0F2
	b _080FB108
_080FB014:
	strh r2, [r7, #0x3e]
	ldr r1, _080FB03C @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _080FB044
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _080FB040 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _080FB0B2
	.align 2, 0
_080FB03C: .4byte 0x0000048A
_080FB040: .4byte 0x03002BE0
_080FB044:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080FB060
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _080FB05C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _080FB0B2
	.align 2, 0
_080FB05C: .4byte 0x03002BE0
_080FB060:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _080FB07C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _080FB078 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _080FB0B2
	.align 2, 0
_080FB078: .4byte 0x03002BE0
_080FB07C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _080FB098
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _080FB094 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _080FB0B2
	.align 2, 0
_080FB094: .4byte 0x03002BE0
_080FB098:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080FB0AA
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _080FB0B2
_080FB0AA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _080FB0B4
_080FB0B2:
	movs r3, #1
_080FB0B4:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _080FB0E8 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _080FB14C
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080FB0EC
	movs r0, #1
	b _080FB0EE
	.align 2, 0
_080FB0E8: .4byte 0x0000049C
_080FB0EC:
	movs r0, #0
_080FB0EE:
	cmp r0, #0
	beq _080FB108
_080FB0F2:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _080FB104 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _080FB114
	.align 2, 0
_080FB104: .4byte 0x03002BE0
_080FB108:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _080FB14C
_080FB114:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_080FB14C:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080FB178
	ldr r5, _080FB184 @ =0x0000024E
	adds r2, r6, r5
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _080FB178
	strh r1, [r2]
_080FB178:
	ldr r5, _080FB188 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _080FB4BC
	.align 2, 0
_080FB184: .4byte 0x0000024E
_080FB188: .4byte 0x0000048C
_080FB18C:
	ldr r0, _080FB1A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080FB1A4
	movs r0, #1
	b _080FB1A6
	.align 2, 0
_080FB1A0: .4byte 0x030047A4
_080FB1A4:
	movs r0, #0
_080FB1A6:
	cmp r0, #0
	beq _080FB1B4
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _080FB1BC
_080FB1B4:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_080FB1BC:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _080FB1F4 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _080FB1F8 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _080FB1EA
	cmp r2, #0x17
	bne _080FB1FC
_080FB1EA:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _080FB21E
	.align 2, 0
_080FB1F4: .4byte 0x0000048C
_080FB1F8: .4byte 0x000001DF
_080FB1FC:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080FB1EA
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _080FB24C @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _080FB21E
	movs r1, #0
_080FB21E:
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _080FB25A
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _080FB250
	asrs r0, r0, #1
	b _080FB256
	.align 2, 0
_080FB24C: .4byte 0x00000187
_080FB250:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080FB256:
	mov r2, sb
	strh r0, [r2]
_080FB25A:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080FB278
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _080FB274 @ =0x000001DD
	adds r1, r6, r4
	b _080FB2EC
	.align 2, 0
_080FB274: .4byte 0x000001DD
_080FB278:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	adds r2, r7, #0
	adds r2, #0xc
	ldrh r0, [r7, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080FB2D8
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _080FB2D8
	ldr r2, _080FB2C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080FB2CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080FB2D0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _080FB2D4 @ =0x000001DD
	adds r1, r6, r4
	b _080FB2EC
	.align 2, 0
_080FB2C8: .4byte 0x030046B8
_080FB2CC: .4byte 0x000003FF
_080FB2D0: .4byte 0x0203B400
_080FB2D4: .4byte 0x000001DD
_080FB2D8:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _080FB30C @ =0x000001DD
	adds r1, r6, r3
_080FB2EC:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080FB314
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _080FB310 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _080FB382
	.align 2, 0
_080FB30C: .4byte 0x000001DD
_080FB310: .4byte 0x03002BE0
_080FB314:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080FB330
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _080FB32C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _080FB382
	.align 2, 0
_080FB32C: .4byte 0x03002BE0
_080FB330:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _080FB34C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _080FB348 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _080FB382
	.align 2, 0
_080FB348: .4byte 0x03002BE0
_080FB34C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _080FB368
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _080FB364 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _080FB382
	.align 2, 0
_080FB364: .4byte 0x03002BE0
_080FB368:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080FB37A
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _080FB382
_080FB37A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _080FB384
_080FB382:
	movs r3, #1
_080FB384:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _080FB3B8 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _080FB420
	movs r1, #2
	ldr r2, _080FB3BC @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080FB3C0
	movs r0, #1
	b _080FB3C2
	.align 2, 0
_080FB3B8: .4byte 0x0000049C
_080FB3BC: .4byte 0x00000474
_080FB3C0:
	movs r0, #0
_080FB3C2:
	cmp r0, #0
	beq _080FB3DC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _080FB3D8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _080FB3E8
	.align 2, 0
_080FB3D8: .4byte 0x03002BE0
_080FB3DC:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _080FB420
_080FB3E8:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_080FB420:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _080FB454
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _080FB454
	ldr r0, _080FB46C @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _080FB454
	strh r1, [r2]
_080FB454:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _080FB470 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _080FB474 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080FB478
	movs r0, #1
	b _080FB47A
	.align 2, 0
_080FB46C: .4byte 0x0000024E
_080FB470: .4byte 0x030046A0
_080FB474: .4byte 0x00000934
_080FB478:
	movs r0, #0
_080FB47A:
	ldr r1, _080FB4CC @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _080FB492
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_080FB492:
	adds r0, r6, #0
	bl FUN_080e64e4
	ldrh r0, [r7, #0x3e]
	strh r0, [r4]
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r1, r6, r4
	mov r5, r8
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080FB4BC:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FB4CC: .4byte 0x0000048A
