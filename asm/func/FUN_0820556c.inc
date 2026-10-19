	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r6, r2, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _082055A6
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	ldr r0, _082055CC @ =0x03003584
	ldr r0, [r0]
	movs r1, #0x8c
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _082055D0 @ =0x04000008
	bl CpuSet
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_082055A6:
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _082055D8
	adds r1, r4, #0
	adds r1, #0xdc
	ldr r0, _082055CC @ =0x03003584
	ldr r0, [r0]
	ldr r2, _082055D4 @ =0x000022E0
	adds r0, r0, r2
	b _0820564E
	.align 2, 0
_082055CC: .4byte 0x03003584
_082055D0: .4byte 0x04000008
_082055D4: .4byte 0x000022E0
_082055D8:
	cmp r6, #0
	bne _082055FC
	ldr r0, _082055F4 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0x8c
	lsls r3, r3, #6
	adds r0, r0, r3
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _082055F8 @ =0x04000008
	bl CpuSet
	b _08205644
	.align 2, 0
_082055F4: .4byte 0x03003584
_082055F8: .4byte 0x04000008
_082055FC:
	adds r5, r6, #0
	subs r5, #0x50
	cmp r5, #0x1f
	bhi _0820562C
	ldr r0, _08205624 @ =0x03003584
	ldr r2, [r0]
	movs r3, #0x8c
	lsls r3, r3, #6
	adds r1, r2, r3
	ldr r0, _08205628 @ =0x000022E0
	adds r2, r2, r0
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r3, #5
	str r3, [sp]
	adds r3, r5, #0
	bl BlendPltt
	b _08205644
	.align 2, 0
_08205624: .4byte 0x03003584
_08205628: .4byte 0x000022E0
_0820562C:
	cmp r6, #0x70
	bne _08205644
	ldr r0, _08205658 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _0820565C @ =0x000022E0
	adds r0, r0, r1
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _08205660 @ =0x04000008
	bl CpuSet
_08205644:
	adds r1, r4, #0
	adds r1, #0xdc
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
_0820564E:
	str r0, [r1, #0xc]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08205658: .4byte 0x03003584
_0820565C: .4byte 0x000022E0
_08205660: .4byte 0x04000008
