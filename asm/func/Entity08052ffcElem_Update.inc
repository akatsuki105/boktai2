	push {r4, lr}
	sub sp, #0x1c
	adds r2, r1, #0
	adds r4, r2, #0
	adds r4, #0x14
	ldr r0, [r2, #0x10]
	cmp r0, #0
	beq _08052F18
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
_08052F18:
	ldr r0, [r2, #4]
	cmp r0, #7
	bhi _08052F2E
	lsls r0, r0, #6
	ldrh r1, [r2, #0xa]
	adds r0, r0, r1
	strh r0, [r4, #0x1e]
	ldr r0, [r2, #4]
	lsls r0, r0, #1
	adds r0, #1
	b _08052F30
_08052F2E:
	movs r0, #0x40
_08052F30:
	strb r0, [r4, #8]
	ldr r0, [r2, #4]
	cmp r0, #0x13
	bls _08052F70
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r3, #0
	strb r3, [r2, #1]
	ldr r0, _08052F6C @ =0x085AB73C
	ldrb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x1c
	movs r0, #0xff
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	movs r0, #0x10
	str r0, [sp, #0x14]
	movs r0, #8
	str r0, [sp, #0x18]
	movs r0, #7
	bl ScatterEffect_SpawnAtAngle
	b _08052F74
	.align 2, 0
_08052F6C: .4byte 0x085AB73C
_08052F70:
	adds r0, #1
	str r0, [r2, #4]
_08052F74:
	add sp, #0x1c
	pop {r4}
	pop {r0}
	bx r0
