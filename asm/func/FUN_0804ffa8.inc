	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x29
	ldrb r0, [r6]
	cmp r0, #0
	beq _0804FFF2
	movs r4, #0
	strb r4, [r6]
	adds r0, r5, #0
	bl FUN_0804fc08
	adds r0, r5, #0
	bl FUN_0804fd3c
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r5, r1
	str r4, [r0]
	bl FUN_0808e420
	ldr r0, _08050058 @ =FUN_0804fb24
	adds r1, r5, #0
	adds r1, #0x3c
	bl FUN_08051bb0
	adds r0, r5, #0
	adds r0, #0x33
	strb r4, [r0]
	adds r1, r5, #0
	adds r1, #0x31
	movs r0, #8
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_0804fbd0
_0804FFF2:
	ldr r0, _0805005C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08050010
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #1
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x31
	movs r0, #8
	strb r0, [r1]
_08050010:
	adds r0, r5, #0
	adds r0, #0x33
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050064
	ldr r0, [r5, #0x24]
	cmp r0, #0x10
	bls _08050064
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08050064
	adds r1, r5, #0
	adds r1, #0x31
	ldrb r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	bne _08050060
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #2
	adds r1, r5, #0
	adds r1, #0x28
	strb r0, [r1]
	movs r0, #1
	strb r0, [r6]
	str r4, [r5, #0x24]
	bl FUN_0808e4f4
	adds r0, r5, #0
	bl FUN_0804fbe0
	b _0805006A
	.align 2, 0
_08050058: .4byte FUN_0804fb24
_0805005C: .4byte 0x030044E0
_08050060:
	subs r0, #1
	strb r0, [r1]
_08050064:
	ldr r0, [r5, #0x24]
	adds r0, #1
	str r0, [r5, #0x24]
_0805006A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
