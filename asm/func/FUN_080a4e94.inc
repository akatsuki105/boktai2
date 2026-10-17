	push {r4, r5, r6, lr}
	ldr r4, _080A4EAC @ =0x03002C48
	ldr r0, [r4]
	cmp r0, #0
	beq _080A4EE0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080A4EB8
	b _080A4EE0
	.align 2, 0
_080A4EAC: .4byte 0x03002C48
_080A4EB0:
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r5, r0
	b _080A4EE2
_080A4EB8:
	bl VM_GetValue
	adds r6, r0, #0
	movs r2, #0
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	cmp r2, r1
	bge _080A4EE0
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r5, #0
	movs r3, #0
_080A4ED0:
	ldrh r0, [r1, #0x1c]
	cmp r0, r6
	beq _080A4EB0
	adds r1, #0xb8
	adds r3, #0xb8
	adds r2, #1
	cmp r2, r4
	blt _080A4ED0
_080A4EE0:
	movs r0, #0
_080A4EE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
