	push {r4, lr}
	ldr r0, _08041E00 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _08041DFA
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08040eb0
	cmp r0, #0
	beq _08041DFA
	ldr r1, _08041E04 @ =0x00000227
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #0xd
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08041E08
_08041DFA:
	movs r0, #0
	b _08041E0A
	.align 2, 0
_08041E00: .4byte 0x03002B50
_08041E04: .4byte 0x00000227
_08041E08:
	movs r0, #1
_08041E0A:
	pop {r4}
	pop {r1}
	bx r1
