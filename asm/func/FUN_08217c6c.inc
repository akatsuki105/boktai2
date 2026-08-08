	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0xff
	lsls r0, r0, #5
	adds r4, r7, r0
	ldrh r1, [r4]
	movs r0, #1
	subs r0, r0, r1
	movs r5, #0
	strh r0, [r4]
	movs r1, #0
	ldrsh r6, [r4, r1]
	ldr r1, [r7, #0x38]
	movs r0, #2
	adds r2, r6, #0
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	str r6, [r7, #0x64]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #1
	bne _08217CBE
	ldr r0, _08217CCC @ =0x00001FE6
	adds r1, r7, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0x4f
	bne _08217CBE
	movs r0, #0x4e
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_08217a10
_08217CBE:
	movs r0, #0xdd
	bl PlaySound_082406e0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08217CCC: .4byte 0x00001FE6
