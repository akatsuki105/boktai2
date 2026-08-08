	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807BFB6
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BFB6:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807BFEC
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807BFE4 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0807BFE8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0807BFFA
	.align 2, 0
_0807BFE4: .4byte 0x000002E6
_0807BFE8: .4byte 0x000002E7
_0807BFEC:
	lsrs r1, r1, #0x19
	ldr r2, _0807C034 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0807C038 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0807BFFA:
	strb r0, [r1]
	ldr r1, _0807C03C @ =0x000004A4
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _0807C040 @ =0x000004A6
	adds r0, r4, r2
	strb r3, [r0]
	movs r0, #0x96
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, [sp, #0xc]
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C044 @ =FUN_08073b3c
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C034: .4byte 0x000002E6
_0807C038: .4byte 0x000002E7
_0807C03C: .4byte 0x000004A4
_0807C040: .4byte 0x000004A6
_0807C044: .4byte FUN_08073b3c
