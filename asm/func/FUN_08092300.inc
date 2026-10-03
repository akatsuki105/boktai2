	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	adds r6, r0, #0
	adds r5, r1, #0
	mov r8, r2
	mov sl, r3
	lsls r4, r5, #1
	adds r4, r4, r5
	lsls r4, r4, #5
	ldr r0, _08092390 @ =0x000020A4
	adds r4, r4, r0
	adds r4, r6, r4
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r1, #0xa0
	adds r1, r1, r6
	mov sb, r1
	ldr r1, _08092394 @ =0x00003F9C
	adds r0, r6, r1
	ldrb r0, [r0]
	mov r1, r8
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sb
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r4, #0
	adds r0, #0x20
	mov r1, r8
	bl FUN_080921e8
	lsls r5, r5, #3
	ldr r0, _08092398 @ =0x00003B68
	adds r5, r5, r0
	adds r5, r6, r5
	adds r0, r5, #0
	mov r1, sl
	bl FUN_080921e8
	movs r1, #0x11
	add r8, r1
	mov r1, r8
	lsls r0, r1, #1
	add r0, r8
	lsls r0, r0, #5
	adds r6, r6, r0
	ldr r0, _0809239C @ =0x00000F9E
	adds r6, r6, r0
	ldrh r1, [r6]
	adds r0, r4, #0
	bl FUN_0808ba0c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08092390: .4byte 0x000020A4
_08092394: .4byte 0x00003F9C
_08092398: .4byte 0x00003B68
_0809239C: .4byte 0x00000F9E
