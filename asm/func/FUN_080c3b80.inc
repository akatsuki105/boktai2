	push {lr}
	adds r2, r0, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C3BA0
	ldr r1, _080C3B98 @ =0x000025BE
	adds r0, r2, r1
	movs r1, #2
	strb r1, [r0]
	ldr r3, _080C3B9C @ =0x000025BF
	b _080C3BBC
	.align 2, 0
_080C3B98: .4byte 0x000025BE
_080C3B9C: .4byte 0x000025BF
_080C3BA0:
	ldr r0, _080C3BE0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080C3BE4 @ =0x00000942
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0
	cmp r0, #0
	bne _080C3BB4
	movs r1, #1
_080C3BB4:
	ldr r3, _080C3BE8 @ =0x000025BE
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_080C3BBC:
	adds r0, r2, r3
	strb r1, [r0]
	subs r3, #2
	adds r0, r2, r3
	strb r1, [r0]
	ldr r0, _080C3BEC @ =0x000025C1
	adds r1, r2, r0
	movs r0, #0x10
	strb r0, [r1]
	adds r3, #3
	adds r1, r2, r3
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_080c3af4
	pop {r0}
	bx r0
	.align 2, 0
_080C3BE0: .4byte 0x030046A0
_080C3BE4: .4byte 0x00000942
_080C3BE8: .4byte 0x000025BE
_080C3BEC: .4byte 0x000025C1
