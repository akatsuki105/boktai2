	push {lr}
	adds r1, r0, #0
	ldr r0, _0809C578 @ =0x0300013C
	ldr r2, [r0]
	cmp r2, #0
	beq _0809C572
	ldr r3, _0809C57C @ =0x00000A9C
	adds r0, r2, r3
	str r1, [r0]
	ldr r1, _0809C580 @ =0x00000A97
	adds r0, r2, r1
	movs r3, #1
	strb r3, [r0]
	ldr r0, _0809C584 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809C572
	ldr r1, _0809C588 @ =0x00000A98
	adds r0, r2, r1
	strb r3, [r0]
_0809C572:
	pop {r0}
	bx r0
	.align 2, 0
_0809C578: .4byte 0x0300013C
_0809C57C: .4byte 0x00000A9C
_0809C580: .4byte 0x00000A97
_0809C584: .4byte 0x030047A4
_0809C588: .4byte 0x00000A98
