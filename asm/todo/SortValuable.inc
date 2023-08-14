	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0
	mov r8, r1
	movs r4, #0
	adds r6, r0, #0
	cmp r6, #0xf
	bgt _08242630
_0824260C:
	adds r0, r6, #0
	bl GetValuableItemID
	cmp r0, #0
	bge _0824261A
	adds r4, #1
	b _0824262A
_0824261A:
	movs r0, #1
	add r8, r0
	cmp r4, #0
	ble _0824262A
	subs r1, r6, r4
	adds r0, r6, #0
	bl SwapValuable
_0824262A:
	adds r6, #1
	cmp r6, #0xf
	ble _0824260C
_08242630:
	mov r1, r8
	cmp r1, #1
	ble _08242672
	movs r6, #0
	movs r0, #1
	rsbs r0, r0, #0
	add r0, r8
	mov sb, r0
	cmp r6, sb
	bge _08242672
_08242644:
	adds r5, r6, #0
	adds r7, r6, #1
	cmp r6, r8
	bge _0824266C
_0824264C:
	adds r0, r6, #0
	bl GetValuableItemID
	adds r4, r0, #0
	adds r0, r5, #0
	bl GetValuableItemID
	cmp r4, r0
	ble _08242666
	adds r0, r6, #0
	adds r1, r5, #0
	bl SwapValuable
_08242666:
	adds r5, #1
	cmp r5, r8
	blt _0824264C
_0824266C:
	adds r6, r7, #0
	cmp r6, sb
	blt _08242644
_08242672:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
