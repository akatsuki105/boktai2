	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081623B6
	ldr r1, _0816234C @ =0x0000A7BF
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08162354
	ldr r3, _08162350 @ =0x00000704
	adds r0, r4, r3
	b _081623AC
	.align 2, 0
_0816234C: .4byte 0x0000A7BF
_08162350: .4byte 0x00000704
_08162354:
	movs r1, #0x22
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08162368
	movs r0, #1
	b _0816236A
_08162368:
	movs r0, #0
_0816236A:
	cmp r0, #0
	beq _08162378
	ldr r3, _08162374 @ =0x00000704
	adds r0, r4, r3
	b _081623AC
	.align 2, 0
_08162374: .4byte 0x00000704
_08162378:
	ldr r1, _081623A0 @ =0x00000704
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081623B6
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r1, r4, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bge _081623A4
	adds r0, r5, #0
	bl Cockatrice_TryLookAround
	b _081623A8
	.align 2, 0
_081623A0: .4byte 0x00000704
_081623A4:
	subs r0, r2, #1
	strh r0, [r1]
_081623A8:
	ldr r1, _081623BC @ =0x00000704
	adds r0, r4, r1
_081623AC:
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081623B6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081623BC: .4byte 0x00000704
