	push {r4, r5, lr}
	ldr r0, _08008898 @ =0x03000034
	ldr r4, [r0]
	cmp r4, #0
	beq _080088B4
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x64
	bl VM_GetNamedArgValue
	adds r3, r0, #0
	ldr r1, [r4, #0x1c]
	movs r2, #0
	b _080088AE
	.align 2, 0
_08008898: .4byte 0x03000034
_0800889C:
	ldrb r0, [r1]
	cmp r0, #1
	bne _080088AA
	ldrh r0, [r1, #0x10]
	cmp r0, r5
	bne _080088AA
	strh r3, [r1, #8]
_080088AA:
	adds r2, #1
	adds r1, #0xe8
_080088AE:
	ldr r0, [r4, #0x18]
	cmp r2, r0
	blo _0800889C
_080088B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
