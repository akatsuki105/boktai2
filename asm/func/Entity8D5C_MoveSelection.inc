	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r7, #0
	movs r6, #0
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x24]
	cmp r0, #0
	bge _0805575C
	str r6, [r4, #0x24]
_0805575C:
	ldr r0, [r4, #0x18]
	bl VM_SetPC
	movs r5, #0
	b _0805577C
_08055766:
	bl VM_GetPC
	bl VM_GetValueAtSafe
	adds r7, r0, #0
	bl VM_GetPC
	bl VM_GetValueAt
	adds r6, r0, #0
	adds r5, #1
_0805577C:
	ldr r0, [r4, #0x24]
	cmp r5, r0
	bgt _0805578C
	bl VM_GetPC
	cmp r0, #0
	bne _08055766
	str r5, [r4, #0x24]
_0805578C:
	str r7, [r4, #0x1c]
	str r6, [r4, #0x20]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
