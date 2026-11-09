	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r6, _0817554C @ =0x0000046C
	adds r1, r5, r6
	ldrb r0, [r1]
	cmp r0, #0
	beq _08175550
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08175552
	.align 2, 0
_0817554C: .4byte 0x0000046C
_08175550:
	movs r0, #0
_08175552:
	cmp r0, #0
	beq _08175590
	ldr r0, _08175584 @ =0x00001008
	adds r2, r2, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08175588 @ =0x00000474
	adds r2, r5, r1
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r1, _0817558C @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _08175670
	.align 2, 0
_08175584: .4byte 0x00001008
_08175588: .4byte 0x00000474
_0817558C: .4byte 0xFFEFFFFF
_08175590:
	ldr r1, _081755AC @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x46
	beq _081755D4
	cmp r0, #0x46
	bgt _081755B6
	cmp r0, #0x1e
	beq _081755D4
	cmp r0, #0x1e
	bgt _081755B0
	cmp r0, #0xa
	beq _081755CE
	b _081755DA
	.align 2, 0
_081755AC: .4byte 0x00000484
_081755B0:
	cmp r0, #0x32
	beq _081755D4
	b _081755DA
_081755B6:
	cmp r0, #0x5a
	beq _081755D4
	cmp r0, #0x5a
	bgt _081755C4
	cmp r0, #0x50
	beq _081755D4
	b _081755DA
_081755C4:
	cmp r0, #0x5f
	beq _081755D4
	cmp r0, #0x64
	beq _081755D4
	b _081755DA
_081755CE:
	ldr r0, _0817564C @ =0x000001C5
	bl PlaySound_082406e0
_081755D4:
	adds r0, r5, #0
	bl FUN_08178470
_081755DA:
	ldr r2, _08175650 @ =0x00000484
	adds r4, r5, r2
	ldr r0, [r4]
	cmp r0, #0x1f
	bne _081755EA
	ldr r0, _08175654 @ =0x000003D9
	bl PlaySound_082406e0
_081755EA:
	ldr r3, _08175658 @ =0x00002EE0
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	ldr r0, [r4]
	cmp r0, #0x78
	ble _0817566C
	ldr r3, _0817565C @ =Sandworm_StateDying
	movs r1, #0x11
	ldr r6, _08175660 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08175664 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08175668 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	b _08175670
	.align 2, 0
_0817564C: .4byte 0x000001C5
_08175650: .4byte 0x00000484
_08175654: .4byte 0x000003D9
_08175658: .4byte 0x00002EE0
_0817565C: .4byte Sandworm_StateDying
_08175660: .4byte 0x0000046D
_08175664: .4byte 0x00000469
_08175668: .4byte 0x0000046C
_0817566C:
	adds r0, #1
	str r0, [r4]
_08175670:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
