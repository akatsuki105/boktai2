	push {r4, lr}
	movs r3, #0
	ldr r0, _0801FB30 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r4, [r0]
	ldr r2, _0801FB34 @ =0x085AAA8C
	adds r1, #0x38
	ldrb r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r2
_0801FB26:
	ldr r0, [r1]
	cmp r4, r0
	bne _0801FB38
	movs r0, #0
	b _0801FB42
	.align 2, 0
_0801FB30: .4byte 0x03002BE0
_0801FB34: .4byte 0x085AAA8C
_0801FB38:
	adds r1, #4
	adds r3, #1
	cmp r3, #2
	ble _0801FB26
	movs r0, #1
_0801FB42:
	pop {r4}
	pop {r1}
	bx r1
