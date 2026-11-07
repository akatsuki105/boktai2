	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _0813F08C @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F090
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F092
	.align 2, 0
_0813F08C: .4byte 0x0000046D
_0813F090:
	movs r0, #0
_0813F092:
	cmp r0, #0
	beq _0813F0B8
	ldr r0, _0813F10C @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r2, _0813F110 @ =0x0000066B
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnim
	ldrb r1, [r4, #5]
	ldr r3, _0813F114 @ =0x00000661
	adds r0, r5, r3
	strb r1, [r0]
_0813F0B8:
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	ldr r2, _0813F118 @ =0x0000065E
	adds r1, r5, r2
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _0813F0DC
	movs r3, #0x97
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r1, [r2]
	ldr r0, _0813F11C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_0813F0DC:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0xb
	bls _0813F0EE
	adds r0, r4, #0
	bl EnemyBat_SpawnTrail
_0813F0EE:
	ldr r2, _0813F110 @ =0x0000066B
	adds r0, r5, r2
	ldrb r2, [r0]
	ldr r0, _0813F10C @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	cmp r1, r2
	bge _0813F124
	ldr r3, _0813F120 @ =0xFFFFFF00
	adds r0, r2, r3
	subs r2, r1, r0
	b _0813F126
	.align 2, 0
_0813F10C: .4byte 0x03002BE0
_0813F110: .4byte 0x0000066B
_0813F114: .4byte 0x00000661
_0813F118: .4byte 0x0000065E
_0813F11C: .4byte 0x0000FFFB
_0813F120: .4byte 0xFFFFFF00
_0813F124:
	subs r2, r1, r2
_0813F126:
	ldr r1, _0813F144 @ =0x0000066A
	adds r0, r5, r1
	strb r2, [r0]
	movs r3, #0xcc
	lsls r3, r3, #3
	adds r1, r5, r3
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bls _0813F14C
	ldr r0, _0813F148 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	b _0813F172
	.align 2, 0
_0813F144: .4byte 0x0000066A
_0813F148: .4byte 0x0000046B
_0813F14C:
	ldr r1, _0813F168 @ =0x00000661
	adds r5, r5, r1
	ldrb r0, [r5]
	ldrb r2, [r4, #5]
	cmp r0, r2
	beq _0813F16C
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnim
	ldrb r0, [r4, #5]
	strb r0, [r5]
	b _0813F174
	.align 2, 0
_0813F168: .4byte 0x00000661
_0813F16C:
	ldr r3, _0813F17C @ =0x0000046E
	adds r1, r4, r3
	movs r0, #0
_0813F172:
	strb r0, [r1]
_0813F174:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0813F17C: .4byte 0x0000046E
