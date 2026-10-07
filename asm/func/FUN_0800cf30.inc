	push {r4, r5, r6, lr}
	adds r4, r1, #0
	cmp r2, #0
	blt _0800CF44
	movs r1, #1
	ldr r0, [r4, #4]
	ands r0, r1
	ands r1, r2
	cmp r1, r0
	bne _0800CF7E
_0800CF44:
	adds r6, r4, #0
	adds r6, #0x48
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r5, [r0, #2]
	adds r0, r5, #0
	movs r1, #3
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0800CF60
	adds r0, #4
	b _0800CF6C
_0800CF60:
	ldr r0, _0800CF84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800CF6C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0xa
	ldrsh r0, [r6, r2]
	subs r0, r0, r1
	cmp r0, #0xff
	bgt _0800CF88
_0800CF7E:
	movs r0, #0
	b _0800CF96
	.align 2, 0
_0800CF84: .4byte 0x030046A4
_0800CF88:
	movs r0, #0
	strh r1, [r4, #0x32]
	movs r1, #5
	strb r1, [r4, #3]
	str r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #1]
_0800CF96:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
