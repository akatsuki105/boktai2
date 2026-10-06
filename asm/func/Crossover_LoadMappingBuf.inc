	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0804E744
	bl VM_GetPC
	adds r6, r0, #0
	b _0804E746
_0804E744:
	movs r6, #0
_0804E746:
	cmp r6, #0
	beq _0804E7A8
	bl Crossover_GetMappingBuf
	adds r7, r0, #0
	movs r5, #0
	movs r4, #0
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
_0804E75A:
	adds r0, r6, #0
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	adds r2, r0, #0
	ldrb r1, [r2]
	adds r4, #1
	cmp r1, #0
	beq _0804E7A0
	cmp r5, r8
	beq _0804E7A0
	lsls r0, r5, #1
	adds r3, r0, r7
_0804E778:
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _0804E786
	ldrb r0, [r2]
	strh r0, [r3]
	adds r2, #1
	b _0804E792
_0804E786:
	ldrb r1, [r2, #1]
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	strh r0, [r3]
	adds r2, #2
_0804E792:
	adds r3, #2
	adds r5, #1
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804E7A0
	cmp r5, r8
	bne _0804E778
_0804E7A0:
	cmp r4, #4
	ble _0804E75A
	movs r0, #0
	strh r0, [r7]
_0804E7A8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
