	push {r4, r5, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r4, [r1]
	ldrb r1, [r0, #5]
	adds r5, r1, #0
	adds r5, #0x20
	movs r1, #0xff
	ands r5, r1
	ldr r1, _0817DABC @ =0x0000085C
	adds r3, r4, r1
	ldr r1, [r0, #8]
	ldr r2, [r0, #0xc]
	str r1, [r3]
	str r2, [r3, #4]
	ldr r2, _0817DAC0 @ =0x00000553
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _0817DB06
	asrs r0, r5, #6
	cmp r0, #1
	beq _0817DADA
	cmp r0, #1
	bgt _0817DAC4
	cmp r0, #0
	beq _0817DACE
	b _0817DB82
	.align 2, 0
_0817DABC: .4byte 0x0000085C
_0817DAC0: .4byte 0x00000553
_0817DAC4:
	cmp r0, #2
	beq _0817DAE2
	cmp r0, #3
	beq _0817DAF4
	b _0817DB82
_0817DACE:
	movs r0, #0x86
	lsls r0, r0, #4
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x20
	b _0817DB04
_0817DADA:
	ldrh r0, [r3]
	subs r0, #0x20
	strh r0, [r3]
	b _0817DB06
_0817DAE2:
	ldrh r0, [r3]
	subs r0, #0x30
	strh r0, [r3]
	movs r2, #0x86
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #6
	b _0817DB04
_0817DAF4:
	ldrh r0, [r3]
	adds r0, #0xa
	strh r0, [r3]
	movs r0, #0x86
	lsls r0, r0, #4
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x18
_0817DB04:
	strh r0, [r1]
_0817DB06:
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r2, _0817DB1C @ =0x00000898
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817DB20
	movs r0, #1
	b _0817DB22
	.align 2, 0
_0817DB1C: .4byte 0x00000898
_0817DB20:
	movs r0, #0
_0817DB22:
	cmp r0, #0
	bne _0817DB82
	asrs r1, r5, #6
	cmp r1, #1
	beq _0817DB48
	cmp r1, #1
	bgt _0817DB36
	cmp r1, #0
	beq _0817DB40
	b _0817DB82
_0817DB36:
	cmp r1, #2
	beq _0817DB50
	cmp r1, #3
	beq _0817DB6C
	b _0817DB82
_0817DB40:
	movs r0, #0x86
	lsls r0, r0, #4
	adds r1, r4, r0
	b _0817DB7C
_0817DB48:
	ldr r2, _0817DB4C @ =0x0000085C
	b _0817DB7A
	.align 2, 0
_0817DB4C: .4byte 0x0000085C
_0817DB50:
	ldr r0, _0817DB68 @ =0x0000085C
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x18
	strh r0, [r1]
	movs r2, #0x86
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #6
	b _0817DB80
	.align 2, 0
_0817DB68: .4byte 0x0000085C
_0817DB6C:
	ldr r0, _0817DB88 @ =0x0000085C
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #6
	strh r0, [r1]
	movs r2, #0x86
	lsls r2, r2, #4
_0817DB7A:
	adds r1, r4, r2
_0817DB7C:
	ldrh r0, [r1]
	subs r0, #0x20
_0817DB80:
	strh r0, [r1]
_0817DB82:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0817DB88: .4byte 0x0000085C
