	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #0
	ldr r4, _0819E814 @ =0x00000EC4
	adds r3, r0, r4
_0819E804:
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne _0819E818
	movs r0, #1
	b _0819E820
	.align 2, 0
_0819E814: .4byte 0x00000EC4
_0819E818:
	adds r2, #1
	cmp r2, #2
	ble _0819E804
	movs r0, #0
_0819E820:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
