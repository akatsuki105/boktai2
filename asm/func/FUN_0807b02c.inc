	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807B080 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807B0B2
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_0807b000
	cmp r0, #0
	beq _0807B0B2
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _0807B096
	bl Script_GetValue
	adds r1, r0, #0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _0807B088
	movs r0, #8
	subs r0, r0, r1
	subs r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _0807B084 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	b _0807B094
	.align 2, 0
_0807B080: .4byte 0x03002BE0
_0807B084: .4byte 0x000002E7
_0807B088:
	ldr r2, _0807B0B8 @ =0x000002E6
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0807B0BC @ =0x000002E7
	adds r1, r5, r0
	movs r0, #0
_0807B094:
	strb r0, [r1]
_0807B096:
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_0823280c
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	adds r0, r5, #0
	bl FUN_08060c60
_0807B0B2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B0B8: .4byte 0x000002E6
_0807B0BC: .4byte 0x000002E7
