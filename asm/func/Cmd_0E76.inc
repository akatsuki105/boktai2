	push {r4, r5, r6, r7, lr}
	ldr r0, _0800378C @ =0x03000020
	ldr r6, [r0]
	cmp r6, #0
	bne _08003790
	movs r0, #1
	rsbs r0, r0, #0
	b _080037C2
	.align 2, 0
_0800378C: .4byte 0x03000020
_08003790:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r7, r0, #0
	ldr r4, [r6, #0x70]
	movs r5, #0
	b _080037BA
_080037A0:
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _080037B2
	ldrh r0, [r4, #0x2c]
	cmp r0, r7
	bne _080037B2
	adds r0, r4, #0
	bl EntityD9AEElem_Release
_080037B2:
	movs r0, #0xce
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, #1
_080037BA:
	ldrh r0, [r6, #0x18]
	cmp r5, r0
	blt _080037A0
	movs r0, #0
_080037C2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
