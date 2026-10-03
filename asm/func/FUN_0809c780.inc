	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	movs r0, #0
	bl FUN_0808a420
	adds r2, r0, #0
	cmp r4, #1
	bne _0809C7A0
	ldr r3, _0809C79C @ =0x0000029F
	b _0809C7F6
	.align 2, 0
_0809C79C: .4byte 0x0000029F
_0809C7A0:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x10
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809C7EC
	ldr r3, _0809C7E4 @ =0x00000A04
	adds r0, r5, r3
	ldrh r0, [r0]
	ldr r3, _0809C7E8 @ =0x0000029F
	cmp r0, #0x24
	bls _0809C7CA
	subs r3, #0xa4
	cmp r0, #0x2c
	bls _0809C7CA
	cmp r0, #0x34
	bhi _0809C7CA
	subs r3, #0x84
_0809C7CA:
	ldr r0, _0809C7E4 @ =0x00000A04
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0809C7F6
	movs r0, #0
	strh r0, [r1]
	b _0809C7F6
	.align 2, 0
_0809C7E4: .4byte 0x00000A04
_0809C7E8: .4byte 0x0000029F
_0809C7EC:
	ldr r3, _0809C818 @ =0x00000A04
	adds r1, r5, r3
	movs r0, #0x34
	strh r0, [r1]
	ldr r3, _0809C81C @ =0x00000177
_0809C7F6:
	ldr r1, _0809C820 @ =0x03004404
	ldrh r0, [r1]
	cmp r0, r3
	beq _0809C800
	strh r3, [r1]
_0809C800:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x18]
	ldr r0, _0809C824 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809C828
	movs r0, #0
	b _0809C82E
	.align 2, 0
_0809C818: .4byte 0x00000A04
_0809C81C: .4byte 0x00000177
_0809C820: .4byte 0x03004404
_0809C824: .4byte 0x03002C68
_0809C828:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_0809C82E:
	adds r1, r0, #0
	ldr r3, _0809C870 @ =0x0000D05C
	adds r0, r3, #0
	strh r0, [r2]
	adds r2, #2
	movs r0, #0
	cmp r0, r1
	bge _0809C850
	ldr r0, _0809C874 @ =0x0000D05D
	adds r3, r0, #0
	adds r0, r1, #0
_0809C844:
	strh r3, [r2]
	adds r2, #2
	subs r0, #1
	cmp r0, #0
	bne _0809C844
	adds r0, r1, #0
_0809C850:
	cmp r0, #9
	bgt _0809C862
	ldr r3, _0809C878 @ =0x0000D05E
	adds r1, r3, #0
_0809C858:
	strh r1, [r2]
	adds r2, #2
	adds r0, #1
	cmp r0, #9
	ble _0809C858
_0809C862:
	ldr r1, _0809C87C @ =0x0000D05F
	adds r0, r1, #0
	strh r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809C870: .4byte 0x0000D05C
_0809C874: .4byte 0x0000D05D
_0809C878: .4byte 0x0000D05E
_0809C87C: .4byte 0x0000D05F
