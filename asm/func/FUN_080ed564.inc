	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl FUN_080ef840
	ldr r0, _080ED5FC @ =0x03002C60
	ldr r0, [r0]
	mov r8, r0
	ldr r4, [r0, #4]
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp]
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	cmp r4, #0
	bne _080ED596
	b _080ED710
_080ED596:
	movs r0, #0
	mov sl, r0
	movs r7, #0
	movs r1, #1
	mov sb, r1
_080ED5A0:
	movs r2, #2
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	bne _080ED5B4
	b _080ED6B8
_080ED5B4:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bgt _080ED5C4
	b _080ED6B8
_080ED5C4:
	cmp r6, #0
	beq _080ED5D4
	ldr r2, _080ED600 @ =0x000001DF
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r6, r0
	beq _080ED5D4
	b _080ED702
_080ED5D4:
	strh r7, [r1]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r7, [r0]
	strh r7, [r4, #8]
	ldr r0, _080ED604 @ =0x00007530
	strh r0, [r4, #0xa]
	strh r7, [r4, #0xc]
	movs r2, #1
	adds r1, #0xcb
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080ED608
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080ED612
	.align 2, 0
_080ED5FC: .4byte 0x03002C60
_080ED600: .4byte 0x000001DF
_080ED604: .4byte 0x00007530
_080ED608:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_080ED612:
	movs r1, #0x10
	ldr r2, _080ED678 @ =0x0000046D
	adds r0, r4, r2
	mov r2, sb
	strb r2, [r0]
	ldr r2, _080ED67C @ =0x0000046B
	adds r0, r4, r2
	strb r7, [r0]
	adds r2, #0xe8
	adds r0, r4, r2
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r2, _080ED680 @ =FUN_080e48d0
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r7, [r0]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _080ED684 @ =0x00000469
	adds r0, r4, r1
	mov r2, sl
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _080ED688 @ =0x00000484
	adds r0, r4, r2
	str r7, [r0]
	adds r1, #2
	adds r0, r4, r1
	mov r2, sb
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_080e49c4
	ldr r0, _080ED68C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080ED690
	movs r0, #1
	b _080ED692
	.align 2, 0
_080ED678: .4byte 0x0000046D
_080ED67C: .4byte 0x0000046B
_080ED680: .4byte FUN_080e48d0
_080ED684: .4byte 0x00000469
_080ED688: .4byte 0x00000484
_080ED68C: .4byte 0x030047A4
_080ED690:
	movs r0, #0
_080ED692:
	cmp r0, #0
	bne _080ED702
	movs r1, #0x80
	lsls r1, r1, #4
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080ED702
	ldr r0, _080ED6B4 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r4]
	bl FUN_080ec5b4
	b _080ED702
	.align 2, 0
_080ED6B4: .4byte 0x03002B28
_080ED6B8:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080ED702
	cmp r6, #0
	beq _080ED6D4
	ldr r2, _080ED720 @ =0x000001DF
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r6, r0
	bne _080ED702
_080ED6D4:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #0xe
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	ldr r0, [sp]
	cmp r0, #0
	beq _080ED702
	movs r2, #0x80
	lsls r2, r2, #0xf
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080ED702:
	mov r1, r8
	ldr r1, [r1]
	mov r8, r1
	ldr r4, [r1, #4]
	cmp r4, #0
	beq _080ED710
	b _080ED5A0
_080ED710:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ED720: .4byte 0x000001DF
