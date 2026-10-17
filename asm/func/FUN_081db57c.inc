	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DB5D0
	bl FUN_08049f5c
	movs r2, #1
	movs r0, #0xc4
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl FUN_08049e5c
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #9
	bl Textbox_LookupString
	bl FUN_08049e30
	adds r0, r5, #0
	bl FUN_081db4b0
	ldr r2, _081DB5F0 @ =0x0000032D
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	ldr r1, _081DB5F4 @ =0x0000032E
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	strb r1, [r4]
_081DB5D0:
	ldr r2, _081DB5F4 @ =0x0000032E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0x1d
	bhi _081DB5F8
	adds r0, r5, #0
	bl FUN_081db370
	adds r0, r5, #0
	bl FUN_081daff0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _081DB8D0
	.align 2, 0
_081DB5F0: .4byte 0x0000032D
_081DB5F4: .4byte 0x0000032E
_081DB5F8:
	ldr r1, _081DB614 @ =0x0000032D
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r2, _081DB618 @ =0x00000321
	adds r6, r5, r2
	movs r3, #0
	ldr r1, _081DB61C @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DB620
	movs r3, #1
	b _081DB65A
	.align 2, 0
_081DB614: .4byte 0x0000032D
_081DB618: .4byte 0x00000321
_081DB61C: .4byte 0x030044E0
_081DB620:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DB62C
	movs r3, #2
	b _081DB65A
_081DB62C:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081DB638
	movs r3, #4
	b _081DB65A
_081DB638:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081DB644
	movs r3, #8
	b _081DB65A
_081DB644:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081DB650
	movs r3, #0x20
	b _081DB65A
_081DB650:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081DB65A
	movs r3, #0x10
_081DB65A:
	ldrh r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	beq _081DB6A2
	ldrb r0, [r6]
	cmp r0, #0xb
	bls _081DB6A0
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DB676
	movs r0, #1
	b _081DB680
_081DB676:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DB682
	movs r0, #2
_081DB680:
	orrs r3, r0
_081DB682:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081DB690
	movs r0, #4
	b _081DB69A
_081DB690:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081DB69C
	movs r0, #8
_081DB69A:
	orrs r3, r0
_081DB69C:
	movs r0, #0
	b _081DB6A2
_081DB6A0:
	adds r0, #1
_081DB6A2:
	strb r0, [r6]
	movs r1, #0
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _081DB6BA
	cmp r4, #0
	bne _081DB6B6
	movs r4, #2
	b _081DB83C
_081DB6B6:
	subs r4, #1
	b _081DB83C
_081DB6BA:
	movs r0, #2
	ands r0, r3
	cmp r0, #0
	beq _081DB6D8
	cmp r4, #2
	bne _081DB6CA
	movs r4, #0
	b _081DB6CC
_081DB6CA:
	adds r4, #1
_081DB6CC:
	ldr r2, _081DB6D4 @ =0x00000321
	adds r1, r5, r2
	b _081DB840
	.align 2, 0
_081DB6D4: .4byte 0x00000321
_081DB6D8:
	movs r0, #4
	ands r0, r3
	cmp r0, #0
	beq _081DB77A
	ldr r2, _081DB6F4 @ =0x0000032D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB730
	cmp r0, #1
	bgt _081DB6F8
	cmp r0, #0
	beq _081DB6FE
	b _081DB82C
	.align 2, 0
_081DB6F4: .4byte 0x0000032D
_081DB6F8:
	cmp r0, #2
	beq _081DB750
	b _081DB82C
_081DB6FE:
	ldr r0, _081DB71C @ =0x00000325
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #1
	bne _081DB70A
	b _081DB82C
_081DB70A:
	ldr r1, _081DB720 @ =0x00000322
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DB724
	ldrb r0, [r2]
	subs r1, r0, #1
	b _081DB726
	.align 2, 0
_081DB71C: .4byte 0x00000325
_081DB720: .4byte 0x00000322
_081DB724:
	subs r1, #1
_081DB726:
	ldr r2, _081DB72C @ =0x00000322
	b _081DB7F8
	.align 2, 0
_081DB72C: .4byte 0x00000322
_081DB730:
	ldr r1, _081DB744 @ =0x00000323
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DB74C
	ldr r2, _081DB748 @ =0x00000326
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DB7F6
	.align 2, 0
_081DB744: .4byte 0x00000323
_081DB748: .4byte 0x00000326
_081DB74C:
	subs r1, #1
	b _081DB7F6
_081DB750:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DB76C
	ldr r2, _081DB768 @ =0x00000327
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DB76E
	.align 2, 0
_081DB768: .4byte 0x00000327
_081DB76C:
	subs r1, #1
_081DB76E:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r1, #1
	b _081DB830
_081DB77A:
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _081DB84C
	ldr r2, _081DB798 @ =0x0000032D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB7D4
	cmp r0, #1
	bgt _081DB79C
	cmp r0, #0
	beq _081DB7A2
	b _081DB82C
	.align 2, 0
_081DB798: .4byte 0x0000032D
_081DB79C:
	cmp r0, #2
	beq _081DB804
	b _081DB82C
_081DB7A2:
	ldr r0, _081DB7C0 @ =0x00000325
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #1
	beq _081DB82C
	ldr r1, _081DB7C4 @ =0x00000322
	adds r0, r5, r1
	ldrb r1, [r0]
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	bne _081DB7C8
	movs r1, #0
	b _081DB7CA
	.align 2, 0
_081DB7C0: .4byte 0x00000325
_081DB7C4: .4byte 0x00000322
_081DB7C8:
	adds r1, #1
_081DB7CA:
	ldr r2, _081DB7D0 @ =0x00000322
	b _081DB7F8
	.align 2, 0
_081DB7D0: .4byte 0x00000322
_081DB7D4:
	ldr r1, _081DB7EC @ =0x00000323
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _081DB7F0 @ =0x00000326
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _081DB7F4
	movs r1, #0
	b _081DB7F6
	.align 2, 0
_081DB7EC: .4byte 0x00000323
_081DB7F0: .4byte 0x00000326
_081DB7F4:
	adds r1, #1
_081DB7F6:
	ldr r2, _081DB800 @ =0x00000323
_081DB7F8:
	adds r0, r5, r2
	strb r1, [r0]
	b _081DB830
	.align 2, 0
_081DB800: .4byte 0x00000323
_081DB804:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _081DB81C @ =0x00000327
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _081DB820
	movs r1, #0
	b _081DB822
	.align 2, 0
_081DB81C: .4byte 0x00000327
_081DB820:
	adds r1, #1
_081DB822:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r1, #1
_081DB82C:
	cmp r1, #0
	beq _081DB83C
_081DB830:
	adds r0, r5, #0
	bl FUN_081db4b0
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DB83C:
	ldr r0, _081DB848 @ =0x00000321
	adds r1, r5, r0
_081DB840:
	movs r0, #0
	strb r0, [r1]
	b _081DB8AC
	.align 2, 0
_081DB848: .4byte 0x00000321
_081DB84C:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _081DB87E
	adds r0, r5, #0
	bl FUN_081dae74
	movs r0, #1
	bl FUN_081df95c
	movs r0, #0xdd
	bl PlaySound_082406e0
	bl FUN_08049fa8
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	bl FUN_081db2f4
	b _081DB8A4
_081DB87E:
	movs r0, #0x10
	ands r3, r0
	cmp r3, #0
	beq _081DB8AC
	movs r0, #2
	bl FUN_081df95c
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	bl FUN_081db2f4
	movs r0, #0xde
	bl PlaySound_082406e0
_081DB8A4:
	adds r0, r5, #0
	bl KillEntity
	b _081DB8D0
_081DB8AC:
	ldr r2, _081DB8D8 @ =0x0000032D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, r4
	beq _081DB8C4
	strb r4, [r1]
	adds r0, r5, #0
	bl FUN_081db1e8
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DB8C4:
	adds r0, r5, #0
	bl FUN_081db370
	adds r0, r5, #0
	bl FUN_081daff0
_081DB8D0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DB8D8: .4byte 0x0000032D
