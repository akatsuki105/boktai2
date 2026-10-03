	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r2
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r7, r2
	ldr r6, [r0]
	cmp r6, #0
	beq _08091856
	ldr r3, _0809182C @ =0x00000366
	adds r5, r6, r3
	ldrh r0, [r5]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	ldr r2, _08091830 @ =0x00003FA2
	adds r1, r7, r2
	strh r0, [r1]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r2, r6, r3
	ldrh r4, [r2]
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r3, r4, r0
	ldrh r0, [r5]
	cmp r3, r0
	ble _08091834
	subs r0, r0, r4
	strh r0, [r1]
	ldrh r0, [r5]
	strh r0, [r2]
	b _08091836
	.align 2, 0
_0809182C: .4byte 0x00000366
_08091830: .4byte 0x00003FA2
_08091834:
	strh r3, [r2]
_08091836:
	adds r0, r7, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	mov r0, r8
	cmp r0, #0
	ble _08091856
	lsls r2, r0, #4
	subs r2, r2, r0
	lsls r2, r2, #2
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08063574
_08091856:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
