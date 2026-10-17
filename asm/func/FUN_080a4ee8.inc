	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4F4E
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4F4E
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x78
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x7a
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x7c
	strh r0, [r1]
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4F4E
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x80
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A4F4E
	ldrb r1, [r4, #2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #2]
	ldr r0, [r4, #0x44]
	ldr r1, [r4, #0x48]
	str r0, [r4, #0x70]
	str r1, [r4, #0x74]
	adds r1, r4, #0
	adds r1, #0x82
	movs r0, #0
	strh r0, [r1]
_080A4F4E:
	pop {r4}
	pop {r0}
	bx r0
