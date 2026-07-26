	push {r4, lr}
	adds r2, r1, #0
	ldr r1, _08242B54 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x60
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bge _08242B5C
	adds r1, r2, #0
	ldr r0, _08242B58 @ =gWeaponDB
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	b _08242B66
	.align 2, 0
_08242B54: .4byte 0x030046A0
_08242B58: .4byte gWeaponDB
_08242B5C:
	movs r4, #0
	ldrsh r0, [r1, r4]
	adds r1, r2, #0
	bl FUN_08242b14
_08242B66:
	pop {r4}
	pop {r0}
	bx r0
