	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldr r0, [r4, #0x40]
	cmp r0, #0
	ble _081F7602
	subs r0, #1
	str r0, [r4, #0x40]
	b _081F761C
_081F7602:
	adds r0, r4, #0
	adds r0, #0x2c
	ldr r1, [r4, #0x3c]
	movs r2, #0
	str r2, [sp]
	movs r2, #1
	movs r3, #1
	bl AuxAnim_SetAnim
	adds r1, r4, #0
	adds r1, #0x46
	movs r0, #3
	strb r0, [r1]
_081F761C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
