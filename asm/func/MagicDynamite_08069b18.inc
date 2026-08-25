	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _08069B7C
	movs r2, #0xe4
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08069B44
	ldr r0, _08069B40 @ =0x000003FA
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	b _08069B72
	.align 2, 0
_08069B40: .4byte 0x000003FA
_08069B44:
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08064d6c
	adds r1, r0, #0
	cmp r1, #0
	beq _08069B6C
	ldr r1, _08069B68 @ =0x000003FA
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080a8ff8
	b _08069B72
	.align 2, 0
_08069B68: .4byte 0x000003FA
_08069B6C:
	ldr r2, _08069B90 @ =0x000003FA
	adds r0, r4, r2
	strb r1, [r0]
_08069B72:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0
	bl FUN_08060b84
_08069B7C:
	ldr r1, _08069B94 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08069BF8
	cmp r0, #1
	bgt _08069B98
	cmp r0, #0
	beq _08069BA2
	b _08069C84
	.align 2, 0
_08069B90: .4byte 0x000003FA
_08069B94: .4byte 0x0000037D
_08069B98:
	cmp r0, #2
	beq _08069C30
	cmp r0, #3
	beq _08069C6C
	b _08069C84
_08069BA2:
	ldr r2, _08069BE0 @ =0x000003FA
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #0
	beq _08069BBE
	ldr r0, _08069BE4 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _08069BE8 @ =0x00000123
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x20
	strh r0, [r1]
_08069BBE:
	adds r0, r4, #0
	movs r1, #0xb8
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069C84
	ldrb r0, [r5]
	cmp r0, #0
	beq _08069BEC
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #1
	bl FUN_08060b84
	b _08069C84
	.align 2, 0
_08069BE0: .4byte 0x000003FA
_08069BE4: .4byte 0x0000095E
_08069BE8: .4byte 0x00000123
_08069BEC:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #2
	bl FUN_08060b84
	b _08069C84
_08069BF8:
	ldr r1, _08069C20 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08069C14
	ldr r2, _08069C24 @ =0x0000095E
	adds r1, r4, r2
	ldr r0, _08069C28 @ =0x00000123
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_08069C14:
	ldr r2, _08069C2C @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08069C52
	.align 2, 0
_08069C20: .4byte 0x000003FA
_08069C24: .4byte 0x0000095E
_08069C28: .4byte 0x00000123
_08069C2C: .4byte 0x0000037E
_08069C30:
	ldr r0, _08069C68 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _08069C42
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08069C42:
	adds r0, r4, #0
	movs r1, #0xc2
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_08069C52:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _08069C84
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #3
	bl FUN_08060b84
	b _08069C84
	.align 2, 0
_08069C68: .4byte 0x0000037E
_08069C6C:
	adds r0, r4, #0
	movs r1, #0xbd
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069C84
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08060b84
_08069C84:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
