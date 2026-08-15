	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl FUN_080ef840
	cmp r0, #0
	beq _080ED9BA
	ldr r0, _080ED944 @ =0x03002C60
	ldr r5, [r0]
	ldr r4, [r5, #4]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	cmp r4, #0
	beq _080ED9BA
	movs r7, #0
	ldr r0, _080ED948 @ =FUN_080e48d0
	mov sl, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov sb, r1
	movs r2, #0x10
	mov r8, r2
_080ED926:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080ED9B2
	ldr r1, _080ED94C @ =0x00000474
	adds r0, r4, r1
	ldrh r0, [r0]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _080ED950
	movs r0, #1
	b _080ED952
	.align 2, 0
_080ED944: .4byte 0x03002C60
_080ED948: .4byte FUN_080e48d0
_080ED94C: .4byte 0x00000474
_080ED950:
	movs r0, #0
_080ED952:
	cmp r0, #0
	beq _080ED9B2
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _080ED9C8 @ =0x00000469
	adds r0, r4, r1
	strb r7, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r7, [r0]
	adds r1, #0x1b
	adds r0, r4, r1
	str r7, [r0]
	adds r2, #2
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	cmp r6, #0
	bne _080ED9A2
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _080ED9CC @ =0x0000046B
	adds r0, r4, r1
	strb r6, [r0]
	adds r2, #0xe6
	adds r0, r4, r2
	mov r1, r8
	strb r1, [r0]
	adds r2, #0x25
	adds r0, r4, r2
	mov r1, sl
	str r1, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r6, [r0]
_080ED9A2:
	movs r0, #0x80
	lsls r0, r0, #7
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080ED9B2:
	ldr r5, [r5]
	ldr r4, [r5, #4]
	cmp r4, #0
	bne _080ED926
_080ED9BA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ED9C8: .4byte 0x00000469
_080ED9CC: .4byte 0x0000046B
