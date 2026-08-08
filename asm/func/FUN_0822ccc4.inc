	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _0822CCDC @ =0x0000C091
	adds r1, r4, #0
	bl FUN_082310cc
	adds r2, r0, #0
	cmp r2, #0
	bne _0822CCE0
	movs r0, #0
	b _0822CD10
	.align 2, 0
_0822CCDC: .4byte 0x0000C091
_0822CCE0:
	ldrb r0, [r2]
	cmp r0, #0x4d
	bne _0822CCEC
	ldrb r0, [r2, #1]
	cmp r0, #0x50
	beq _0822CCF4
_0822CCEC:
	ldr r1, [r2]
	ldr r0, _0822CCF8 @ =0x005E8CC5
	cmp r1, r0
	bne _0822CCFC
_0822CCF4:
	adds r0, r2, #0
	b _0822CD10
	.align 2, 0
_0822CCF8: .4byte 0x005E8CC5
_0822CCFC:
	ldr r1, _0822CD18 @ =0x03000688
	ldrh r0, [r1]
	cmp r0, r4
	beq _0822CD0E
	strh r4, [r1]
	ldr r1, _0822CD1C @ =0x02021400
	adds r0, r2, #0
	bl LZ77UnCompReadNormalWrite8bit
_0822CD0E:
	ldr r0, _0822CD20 @ =0x02021404
_0822CD10:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0822CD18: .4byte 0x03000688
_0822CD1C: .4byte 0x02021400
_0822CD20: .4byte 0x02021404
