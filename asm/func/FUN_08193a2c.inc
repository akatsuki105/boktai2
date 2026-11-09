	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #0
	ldr r4, _08193A4C @ =0x00000E44
	adds r3, r0, r4
_08193A3C:
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne _08193A50
	movs r0, #1
	b _08193A58
	.align 2, 0
_08193A4C: .4byte 0x00000E44
_08193A50:
	adds r2, #1
	cmp r2, #2
	ble _08193A3C
	movs r0, #0
_08193A58:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
