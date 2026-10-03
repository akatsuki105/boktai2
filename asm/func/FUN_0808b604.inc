	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	movs r1, #1
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_0808a610
	adds r3, r6, #1
	adds r0, r5, #0
	movs r1, #1
	adds r2, r4, #0
	bl FUN_0808a768
	ldr r5, _0808B66C @ =0x030046A0
	ldr r0, [r5]
	adds r0, #0x58
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r1, sp, #4
	bl FUN_08242b28
	add r0, sp, #4
	bl FUN_0807a6cc
	adds r4, #1
	adds r3, r6, #2
	movs r7, #0
	str r7, [sp]
	movs r1, #0x64
	adds r2, r4, #0
	bl FUN_0808b30c
	ldr r5, [r5]
	adds r1, r5, #0
	adds r1, #0x5c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0808B670
	movs r0, #0
	bl FUN_0807a70c
	adds r3, r6, #3
	str r7, [sp]
	movs r1, #0x64
	adds r2, r4, #0
	bl FUN_0808b30c
	b _0808B698
	.align 2, 0
_0808B66C: .4byte 0x030046A0
_0808B670:
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	ldr r1, _0808B6A0 @ =0x08DAA7B0
	adds r0, r0, r1
	bl FUN_0807a70c
	adds r3, r6, #3
	str r7, [sp]
	movs r1, #0x64
	adds r2, r4, #0
	bl FUN_0808b30c
_0808B698:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B6A0: .4byte 0x08DAA7B0
