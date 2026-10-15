	push {r4, r5, r6, lr}
	ldr r4, _080A5968 @ =0x03002C4C
	ldr r0, [r4]
	cmp r0, #0
	beq _080A599E
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080A5974
	b _080A599E
	.align 2, 0
_080A5968: .4byte 0x03002C4C
_080A596C:
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r5, r0
	b _080A59A0
_080A5974:
	bl VM_GetValue
	adds r6, r0, #0
	movs r2, #0
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	cmp r2, r1
	bge _080A599E
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r5, #0
	adds r1, #0xb4
	movs r3, #0
_080A598E:
	ldrh r0, [r1]
	cmp r0, r6
	beq _080A596C
	adds r1, #0xbc
	adds r3, #0xbc
	adds r2, #1
	cmp r2, r4
	blt _080A598E
_080A599E:
	movs r0, #0
_080A59A0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
