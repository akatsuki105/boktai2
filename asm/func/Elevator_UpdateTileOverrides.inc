	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	ldr r0, _081D3244 @ =0x03000194
	ldr r1, [r0]
	cmp r1, #0
	beq _081D323C
	mov r0, r8
	adds r0, #0xd4
	ldr r2, _081D3248 @ =0x000012B0
	adds r1, r1, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D323C
	mov r0, r8
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #2
	beq _081D323C
	ldr r0, _081D324C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _081D323C
	mov r0, r8
	adds r0, #0xb2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #3
	beq _081D3250
_081D323C:
	mov r0, r8
	bl Elevator_RemoveTileOverrides
	b _081D33E2
	.align 2, 0
_081D3244: .4byte 0x03000194
_081D3248: .4byte 0x000012B0
_081D324C: .4byte 0x03002BE0
_081D3250:
	movs r2, #0x80
	lsls r2, r2, #4
	mov r1, r8
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x14]
	cmp r0, #0
	beq _081D3266
	movs r0, #1
	b _081D3268
_081D3266:
	movs r0, #0
_081D3268:
	cmp r0, #0
	beq _081D326E
	b _081D33E2
_081D326E:
	mov r0, r8
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3296
	cmp r1, #0
	blt _081D3296
	ldr r0, _081D329C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3296
	ldr r0, _081D32A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D32A4
_081D3296:
	movs r0, #0
	b _081D32B2
	.align 2, 0
_081D329C: .4byte 0x030046A8
_081D32A0: .4byte 0x030046AC
_081D32A4:
	ldr r0, _081D32D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D32B2:
	str r0, [sp, #0x10]
	ldr r5, [sp, #0x10]
	adds r5, #1
	movs r1, #0
	mov sl, r1
	movs r2, #0xa4
	lsls r2, r2, #1
	add r2, r8
	str r2, [sp, #0x18]
_081D32C4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D32D8
	adds r0, #4
	b _081D32E4
	.align 2, 0
_081D32D4: .4byte 0x030046A4
_081D32D8:
	ldr r0, _081D32F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D32E4:
	ldrh r0, [r0, #2]
	movs r1, #0xc0
	ands r0, r1
	cmp r0, #0
	bne _081D32F8
	movs r0, #0
	b _081D32FA
	.align 2, 0
_081D32F4: .4byte 0x030046A4
_081D32F8:
	movs r0, #1
_081D32FA:
	cmp r0, #0
	beq _081D3390
	mov r0, r8
	adds r0, #0xfe
	ldrh r3, [r0]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r0, #0xff
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	adds r1, r5, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #0xc4
	lsls r0, r0, #1
	add r0, r8
	add r0, sl
	movs r1, #1
	strb r1, [r0]
	add r0, sp, #8
	mov sb, r0
	ldr r6, _081D3364 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #8
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3368
	adds r0, #4
	b _081D3372
	.align 2, 0
_081D3364: .4byte 0x030046A4
_081D3368:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081D3372:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3390:
	mov r0, sl
	cmp r0, #1
	beq _081D33BC
	cmp r0, #1
	bgt _081D33A0
	cmp r0, #0
	beq _081D33A8
	b _081D33D0
_081D33A0:
	mov r1, sl
	cmp r1, #2
	beq _081D33C2
	b _081D33D0
_081D33A8:
	ldr r0, _081D33B8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x10]
	adds r5, r1, r0
	b _081D33D0
	.align 2, 0
_081D33B8: .4byte 0x030046A4
_081D33BC:
	ldr r5, [sp, #0x10]
	subs r5, #1
	b _081D33D0
_081D33C2:
	ldr r0, _081D33F4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x10]
	subs r5, r1, r0
_081D33D0:
	ldr r2, [sp, #0x18]
	adds r2, #0x10
	str r2, [sp, #0x18]
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	bgt _081D33E2
	b _081D32C4
_081D33E2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D33F4: .4byte 0x030046A4
