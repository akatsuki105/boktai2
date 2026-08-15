	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r0, r1, #0
	adds r1, r2, #0
	bl FUN_08231448
	adds r5, r0, #0
_08231AE0:
	cmp r4, #0
	beq _08231B44
	ldrb r0, [r4]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x60
	beq _08231B02
	cmp r1, #0x60
	bgt _08231AFC
	cmp r1, #0
	beq _08231B44
	cmp r1, #0x30
	beq _08231B28
	b _08231AE0
_08231AFC:
	cmp r1, #0x70
	beq _08231B18
	b _08231AE0
_08231B02:
	adds r0, r4, #0
	mov r1, sp
	bl VM_ReadContainerLength
	adds r4, r0, #0
	bl Script_RunControl
	cmp r0, #1
	bne _08231B3A
	movs r4, #1
	b _08231B46
_08231B18:
	adds r0, r4, #0
	mov r1, sp
	bl VM_ReadContainerLength
	adds r4, r0, #0
	bl FUN_082318d0
	b _08231B36
_08231B28:
	adds r0, r4, #0
	mov r1, sp
	bl VM_ReadContainerLength
	adds r4, r0, #0
	bl Script_RunExpression
_08231B36:
	ldr r1, _08231B40 @ =gVM
	str r0, [r1, #4]
_08231B3A:
	ldr r0, [sp]
	adds r4, r4, r0
	b _08231AE0
	.align 2, 0
_08231B40: .4byte gVM
_08231B44:
	movs r4, #0
_08231B46:
	adds r0, r5, #0
	bl FUN_0823146c
	adds r0, r4, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
