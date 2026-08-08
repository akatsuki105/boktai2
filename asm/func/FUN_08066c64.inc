	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r1, _08066CA8 @ =0x000003CE
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08066D04
	ldr r5, _08066CAC @ =0x000003BD
	adds r0, r3, r5
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _08066CB0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r5, r2, #0
	cmp r0, #0
	blt _08066CB4
	asrs r0, r0, #0xc
	b _08066CBA
	.align 2, 0
_08066CA8: .4byte 0x000003CE
_08066CAC: .4byte 0x000003BD
_08066CB0: .4byte 0x085B0A08
_08066CB4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08066CBA:
	rsbs r1, r0, #0
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r3, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _08066CE8 @ =0x000003CA
	adds r0, r3, r1
	strh r2, [r0]
	lsls r0, r4, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	cmp r0, #0
	blt _08066CEC
	asrs r0, r0, #0xc
	b _08066CF2
	.align 2, 0
_08066CE8: .4byte 0x000003CA
_08066CEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08066CF2:
	rsbs r1, r0, #0
	movs r5, #0xf3
	lsls r5, r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	ldr r0, _08066D0C @ =0x000003CE
	adds r1, r3, r0
	movs r0, #1
	strh r0, [r1]
_08066D04:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08066D0C: .4byte 0x000003CE
