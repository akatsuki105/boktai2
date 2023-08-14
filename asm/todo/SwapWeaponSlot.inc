	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	bl GetWeapon
	mov r8, r0
	adds r0, r5, #0
	bl GetWeapon
	adds r7, r0, #0
	mov r1, sp
	mov r0, r8
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	mov r1, r8
	adds r0, r7, #0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	adds r1, r7, #0
	mov r0, sp
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	movs r4, #0
	ldr r0, _08242CB8 @ =0x03002BE0
	mov sb, r0
_08242C96:
	ldr r0, _08242CBC @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r1
	adds r0, #0x60
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, r6
	bne _08242CC0
	strh r5, [r0]
	mov r3, sb
	ldr r0, [r3]
	adds r1, r7, #0
	bl FUN_08064658
	b _08242CD0
	.align 2, 0
_08242CB8: .4byte 0x03002BE0
_08242CBC: .4byte 0x030046A0
_08242CC0:
	cmp r1, r5
	bne _08242CD0
	strh r6, [r0]
	mov r1, sb
	ldr r0, [r1]
	mov r1, r8
	bl FUN_08064658
_08242CD0:
	adds r4, #1
	cmp r4, #3
	ble _08242C96
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
