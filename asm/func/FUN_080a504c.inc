	push {r4, r5, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A50D2
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A50D2
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x90
	strh r0, [r1]
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A50D2
	bl VM_GetValue
	adds r5, r4, #0
	adds r5, #0x92
	strh r0, [r5]
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A50D2
	bl VM_GetValue
	adds r2, r4, #0
	adds r2, #0x96
	strh r0, [r2]
	ldrh r0, [r5]
	adds r3, r4, #0
	adds r3, #0x30
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0x31
	strb r0, [r1]
	ldrh r0, [r2]
	cmp r0, #1
	bhi _080A50BA
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0x40
	beq _080A50D2
	ldr r0, [r4, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r4, #0x28]
	b _080A50D2
_080A50BA:
	ldr r0, [r4, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0x94
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r4, #2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #2]
_080A50D2:
	pop {r4, r5}
	pop {r0}
	bx r0
