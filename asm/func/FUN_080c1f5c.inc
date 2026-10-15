	push {lr}
	ldr r0, _080C1F80 @ =0x03003ED0
	ldr r1, [r0, #0x2c]
	movs r0, #0
	ldr r2, _080C1F84 @ =0x0000F001
	adds r3, r2, #0
_080C1F68:
	adds r2, r0, #1
	movs r0, #0x1f
_080C1F6C:
	strh r3, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _080C1F6C
	adds r0, r2, #0
	cmp r0, #0x1f
	ble _080C1F68
	pop {r0}
	bx r0
	.align 2, 0
_080C1F80: .4byte 0x03003ED0
_080C1F84: .4byte 0x0000F001
