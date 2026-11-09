	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #0
	strb r5, [r0]
	ldr r2, _08187188 @ =0x00000469
	adds r0, r6, r2
	strb r1, [r0]
	ldr r4, _0818718C @ =0x0000046A
	adds r0, r6, r4
	strb r1, [r0]
	adds r2, #0x1b
	adds r0, r6, r2
	str r1, [r0]
	adds r4, #2
	adds r0, r6, r4
	movs r7, #1
	strb r7, [r0]
	ldr r0, _08187190 @ =Octopus_StateVanish
	mov ip, r0
	movs r2, #0x3c
	adds r4, #0xec
	adds r3, r6, r4
	subs r4, #4
	adds r0, r6, r4
	str r2, [r0]
	mov r0, ip
	str r0, [r3]
	movs r2, #0xaa
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	subs r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _08187194 @ =FUN_080e68d8
	movs r2, #0xe
	subs r4, #0xe4
	adds r0, r6, r4
	strb r7, [r0]
	subs r4, #2
	adds r0, r6, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r1, [r0]
	adds r0, r6, #0
	bl Enemy_Reactivate
	ldr r1, _08187198 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818719C
	ldr r1, [r6, #0x44]
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	b _081871A6
	.align 2, 0
_08187188: .4byte 0x00000469
_0818718C: .4byte 0x0000046A
_08187190: .4byte Octopus_StateVanish
_08187194: .4byte FUN_080e68d8
_08187198: .4byte 0x0000025D
_0818719C:
	ldr r1, [r6, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r7
	str r0, [r1, #8]
_081871A6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
