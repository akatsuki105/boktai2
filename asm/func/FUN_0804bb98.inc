	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0xba
	lsls r2, r2, #1
	adds r0, r4, r2
	bl FUN_0823a7d8
	cmp r0, #0
	beq _0804BBE2
	movs r0, #0xfa
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x88
	lsls r2, r2, #1
	adds r3, r4, r2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r4, r0
	adds r4, #0xf0
	movs r5, #4
_0804BBC6:
	ldrh r0, [r3]
	strh r0, [r4]
	ldrh r0, [r2]
	ldrh r1, [r3]
	eors r0, r1
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _0804BBC6
	movs r1, #0
	b _0804BBEA
_0804BBE2:
	movs r1, #2
	rsbs r1, r1, #0
	adds r4, #0xfa
	mov ip, r4
_0804BBEA:
	movs r0, #1
	mov r2, ip
	strb r0, [r2]
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1
