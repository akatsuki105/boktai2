	push {r4, lr}
	ldr r0, _0809C5C8 @ =0x0300013C
	ldr r4, [r0]
	cmp r4, #0
	beq _0809C5C0
	ldr r1, _0809C5CC @ =0x00000A9C
	adds r0, r4, r1
	movs r3, #0
	str r3, [r0]
	ldr r0, _0809C5D0 @ =0x00000AA8
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809C5D4 @ =0x00000B08
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0809C5D8 @ =0x00000A97
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r3, [r0]
_0809C5C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C5C8: .4byte 0x0300013C
_0809C5CC: .4byte 0x00000A9C
_0809C5D0: .4byte 0x00000AA8
_0809C5D4: .4byte 0x00000B08
_0809C5D8: .4byte 0x00000A97
