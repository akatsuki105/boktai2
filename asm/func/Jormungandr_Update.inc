	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080ca69c
	adds r0, r4, #0
	bl FUN_080ca0fc
	adds r0, r4, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0x1e
	bhi _080CAB8C
	ldr r0, _080CAB84 @ =0x000008FE
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080CAB88 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x30
	ldrsh r1, [r0, r2]
	movs r5, #0xbf
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r0, r5
	cmp r1, r0
	bge _080CAB94
	adds r0, r4, #0
	bl FUN_080c5854
	b _080CAB94
	.align 2, 0
_080CAB84: .4byte 0x000008FE
_080CAB88: .4byte 0x03002BE0
_080CAB8C:
	ldr r0, _080CABE4 @ =0x000008FE
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080CAB94:
	adds r0, r4, #0
	bl FUN_080c9cd0
	adds r0, r4, #0
	bl FUN_080c4a74
	adds r0, r4, #0
	bl FUN_080c5828
	adds r0, r4, #0
	bl FUN_080c2d38
	adds r0, r4, #0
	bl FUN_080c373c
	ldr r1, _080CABE8 @ =0x000025BC
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080CABF8
	ldr r5, _080CABEC @ =0x000025BD
	adds r2, r4, r5
	ldrb r1, [r2]
	cmp r1, #2
	beq _080CAC6E
	adds r5, #1
	adds r0, r4, r5
	strb r1, [r0]
	ldr r0, _080CABF0 @ =0x000025BF
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	strb r0, [r2]
	ldr r1, _080CABF4 @ =0x000025C1
	adds r0, r4, r1
	strb r3, [r0]
	movs r2, #0x97
	lsls r2, r2, #6
	adds r1, r4, r2
	b _080CAC6A
	.align 2, 0
_080CABE4: .4byte 0x000008FE
_080CABE8: .4byte 0x000025BC
_080CABEC: .4byte 0x000025BD
_080CABF0: .4byte 0x000025BF
_080CABF4: .4byte 0x000025C1
_080CABF8:
	ldr r0, _080CAC30 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _080CAC34 @ =0x00000942
	adds r0, r0, r5
	movs r1, #0
	ldrsh r3, [r0, r1]
	cmp r3, #0
	bne _080CAC44
	ldr r5, _080CAC38 @ =0x000025BD
	adds r2, r4, r5
	ldrb r1, [r2]
	cmp r1, #1
	beq _080CAC6E
	adds r5, #1
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _080CAC3C @ =0x000025BF
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	strb r1, [r2]
	ldr r2, _080CAC40 @ =0x000025C1
	adds r0, r4, r2
	strb r3, [r0]
	adds r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	b _080CAC6E
	.align 2, 0
_080CAC30: .4byte 0x030046A0
_080CAC34: .4byte 0x00000942
_080CAC38: .4byte 0x000025BD
_080CAC3C: .4byte 0x000025BF
_080CAC40: .4byte 0x000025C1
_080CAC44:
	ldr r0, _080CAC98 @ =0x000025BD
	adds r3, r4, r0
	ldrb r2, [r3]
	cmp r2, #0
	beq _080CAC6E
	ldr r1, _080CAC9C @ =0x000025BE
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _080CACA0 @ =0x000025BF
	adds r0, r4, r2
	strb r1, [r0]
	strb r1, [r3]
	ldr r5, _080CACA4 @ =0x000025C1
	adds r0, r4, r5
	strb r1, [r0]
	movs r0, #0x97
	lsls r0, r0, #6
	adds r1, r4, r0
_080CAC6A:
	movs r0, #1
	strb r0, [r1]
_080CAC6E:
	adds r0, r4, #0
	bl FUN_080c3af4
	adds r0, r4, #0
	bl FUN_080c3bf0
	movs r1, #0x97
	lsls r1, r1, #6
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CACAC
	ldr r2, _080CAC98 @ =0x000025BD
	adds r0, r4, r2
	ldrb r1, [r0]
	cmp r1, #0
	bne _080CACAC
	ldr r5, _080CACA8 @ =0x000025C8
	adds r0, r4, r5
	strb r1, [r0]
	b _080CACB4
	.align 2, 0
_080CAC98: .4byte 0x000025BD
_080CAC9C: .4byte 0x000025BE
_080CACA0: .4byte 0x000025BF
_080CACA4: .4byte 0x000025C1
_080CACA8: .4byte 0x000025C8
_080CACAC:
	ldr r0, _080CACC4 @ =0x000025C8
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080CACB4:
	adds r0, r4, #0
	bl FUN_080ca760
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080CACC4: .4byte 0x000025C8
