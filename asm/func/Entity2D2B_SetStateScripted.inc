	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _080088F0 @ =0x03000034
	ldr r7, [r0]
	cmp r7, #0
	beq _08008912
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r8, r0
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x6d
	adds r1, r4, #0
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	cmp r6, r4
	beq _08008912
	cmp r6, #4
	bgt _08008912
	ldr r4, [r7, #0x1c]
	movs r5, #0
	b _0800890C
	.align 2, 0
_080088F0: .4byte 0x03000034
_080088F4:
	ldrb r0, [r4]
	cmp r0, #1
	bne _08008908
	ldrh r0, [r4, #0x10]
	cmp r0, r8
	bne _08008908
	adds r0, r4, #0
	adds r1, r6, #0
	bl Entity2D2BElem_SetState
_08008908:
	adds r5, #1
	adds r4, #0xe8
_0800890C:
	ldr r0, [r7, #0x18]
	cmp r5, r0
	blo _080088F4
_08008912:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
