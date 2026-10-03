	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	mov sb, r1
	adds r7, r2, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	beq _0809192E
	ldr r4, _080918BC @ =0x0000036A
	add r4, r8
	ldrh r0, [r4]
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	movs r1, #0x64
	bl Div
	ldr r1, _080918C0 @ =0x00003FA2
	adds r6, r5, r1
	strh r0, [r6]
	ldrh r0, [r4]
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	movs r1, #0x64
	bl Div
	movs r2, #0xda
	lsls r2, r2, #2
	add r2, r8
	ldrh r3, [r2]
	adds r1, r3, r0
	ldrh r0, [r4]
	cmp r1, r0
	ble _080918C4
	subs r0, r0, r3
	strh r0, [r6]
	ldrh r0, [r4]
	strh r0, [r2]
	b _080918D0
	.align 2, 0
_080918BC: .4byte 0x0000036A
_080918C0: .4byte 0x00003FA2
_080918C4:
	cmp r1, #0
	bge _080918CE
	movs r0, #0
	strh r0, [r2]
	b _080918D0
_080918CE:
	strh r1, [r2]
_080918D0:
	ldr r0, _08091914 @ =0x00003FA2
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _080918E0
	movs r0, #0
	strh r0, [r1]
_080918E0:
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	cmp r7, #0
	ble _0809192E
	ldr r1, _08091918 @ =0x00003F9C
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r2, _0809191C @ =0x00003AEE
	adds r1, r5, r2
	ldrb r1, [r1]
	bl GetItemID
	cmp r0, #0xb
	bne _08091920
	lsls r2, r7, #4
	subs r2, r2, r7
	lsls r2, r2, #2
	mov r0, r8
	movs r1, #2
	bl FUN_08063574
	b _0809192E
	.align 2, 0
_08091914: .4byte 0x00003FA2
_08091918: .4byte 0x00003F9C
_0809191C: .4byte 0x00003AEE
_08091920:
	lsls r2, r7, #4
	subs r2, r2, r7
	lsls r2, r2, #2
	mov r0, r8
	movs r1, #0
	bl FUN_08063574
_0809192E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
